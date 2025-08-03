module;

#include <cctype>

export module level.draw_level;

import extensions.scheduler.accessors;

import common.textures;
import components.Drawable;
import components.Hitbox;
import components.Solid;
import states.GlobalState;
import states.Textures;

auto get_texture_from_char(char tile_char, int level_index)
{
    const int level_start_row = 1;
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

export auto draw_level(const extensions::scheduler::accessors::Registry& registry,
    extensions::scheduler::accessors::State<GlobalState> global_state)
{
    auto level = global_state->levels[global_state->current_level_index];
    auto& tile_array = global_state->tile_array;

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

        auto tile_texture = get_texture_from_char(tile_char, global_state->current_level_index);
        auto tile_id = tile_array[x][y];
        registry->get_single<Drawable>(tile_id).texture = tile_texture;

        if (tile_char != ' ' && tile_char != '0' && tile_char != 'S' && tile_char != 'V'
            && tile_char != 'H' && tile_char != 'E') {
            registry->insert(tile_id, Hitbox{}, Solid{});
        }

        x++;
    }
}
