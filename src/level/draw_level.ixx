module;

#include <ranges>
#include <vector>

export module level.draw_level;

import extensions.scheduler.accessors;

import common.textures;
import components.Drawable;
import components.Hitbox;
import components.Solid;
import states.GlobalState;
import states.Textures;
import components.Spawner;

auto get_texture_from_char(char tile_char, int level_index)
{
    const int level_start_row = 2;
    const int level_start_texture_offset_y = (level_index + level_start_row) * 32;

    if (std::isdigit(tile_char)) {
        auto index = tile_char - '0';
        return Textures::Texture { {index * 32, level_start_texture_offset_y} };
    }

    switch (tile_char) {
        case 'T': return Textures::Texture { {10 * 32, level_start_texture_offset_y} };
        case 'B': return Textures::Texture { {11 * 32, level_start_texture_offset_y} };
        case 'L': return Textures::Texture { {12 * 32, level_start_texture_offset_y} };
        case 'R': return Textures::Texture { {13 * 32, level_start_texture_offset_y} };
        case 'S': return Textures::Texture { {0 * 32, level_start_texture_offset_y} };
        case 'V': return textures::vertical_door;
        case 'H': return textures::horizontal_door;
        case 'E': return textures::trapdoor;
        case ' ': return textures::nothing;
        default: return textures::debug_tile;
    }
}

std::vector<std::string> split_line(const std::string& s, char delimiter) {
    return s | std::views::split(delimiter)
             | std::views::transform([](auto&& subrange) {
                   return std::string(subrange.begin(), subrange.end());
               })
             | std::ranges::to<std::vector<std::string>>();
}

auto create_spawners(std::string& spawners)
{
    std::vector<Spawner> spawner_objects;

    auto lines = spawners | std::views::split('\n')
                        | std::views::transform([](auto&& r) {
                              std::string line(r.begin(), r.end());
                              if (!line.empty() && line.back() == '\r')
                                  line.pop_back();
                              return line;
                          });

    bool first = true;
    for (auto&& line : lines) {
        if (first) {
            first = false;
            continue;
        }

        auto fields = split_line(line, ',');
        std::vector<std::string> tokens(fields.begin(), fields.end());

        char tile_char = tokens[0][0];
        char type = tokens[1][0];
        int number_of_spawns = std::stoi(tokens[2]);
        int health = std::stoi(tokens[3]);
        float damage = std::stof(tokens[4]);
        float speed = std::stof(tokens[5]);

        spawner_objects.push_back(Spawner{
            .is_active = true,
            .remaining_spawns = number_of_spawns,
            .tile_char = tile_char,
            .enemy_type = type,
            .health = health,
            .damage = damage,
            .movement_speed = speed
        });
    }

    return spawner_objects;
}

std::optional<Spawner> find_spawner_by_tile_char(const std::vector<Spawner>& spawners, char target) {
    for (const auto& spawner : spawners) {
        if (spawner.tile_char == target)
            return spawner;
    }
    return std::nullopt;
}

export auto draw_level(const extensions::scheduler::accessors::Registry& registry,
    extensions::scheduler::accessors::State<GlobalState> global_state)
{
    auto level = global_state->levels[global_state->current_level_index];
    auto& tile_array = global_state->tile_array;

    auto level_spawners = global_state->level_spawners[global_state->current_level_index];
    auto spawners = create_spawners(*level_spawners);

    int x = 0;
    int y = 0;
    for (int i = 0; i < level.get()->length(); ++i) {
        auto tile_char = level.get()->at(i);

        if (tile_char == '\r') {
            continue;
        }
        if (tile_char == '\n') {
            x = 0;
            y++;
            continue;
        }

        if (x > 39 || y > 39) {
            continue;
        }

        auto spawner = find_spawner_by_tile_char(spawners, tile_char);

        if (spawner.has_value()) {
            tile_char = '0'; // Use floor for spawner tiles
        }

        auto tile_texture = get_texture_from_char(tile_char, global_state->current_level_index);
        auto tile_id = tile_array[x][y];
        registry->get_single<Drawable>(tile_id).texture = tile_texture;

        if ((tile_char >= '1' && tile_char <= '8') || tile_char == 'T'
            || tile_char == 'B' || tile_char == 'L' || tile_char == 'R') {
            registry->insert(tile_id, Hitbox{}, Solid{});
        }

        if (spawner.has_value()) {
            registry->insert(tile_id, spawner.value());
        }

        x++;
    }
}
