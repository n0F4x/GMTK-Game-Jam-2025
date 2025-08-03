module;

#include <array>

#include <SFML/System/Vector2.hpp>

module player.animations;

import common.textures;
import components.Animation;

[[nodiscard]]
auto generate_id() -> unsigned
{
    static unsigned next_id{};
    return next_id++;
}

[[nodiscard]]
auto idle_animation_front(const bool has_gun) noexcept -> const Animation&
{
    static const unsigned id{generate_id()};

    if (!has_gun) {
        static const Animation result{
            std::array{
                       textures::player_idle[0],
                       textures::player_idle[0],
                       textures::player_idle[0],

                       textures::player_idle[1],
                       textures::player_idle[1],
                       textures::player_idle[1],
                       textures::player_idle[1],
                       textures::player_idle[1],
                       textures::player_idle[1],
                       textures::player_idle[1],

                       textures::player_idle[0],
                       textures::player_idle[0],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
    else {
        static const Animation result{
            std::array{
                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],

                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],
                       textures::player_with_weapon[1],

                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
}

[[nodiscard]]
auto idle_animation_back(const bool has_gun) noexcept -> const Animation&
{
    static const unsigned id{generate_id()};

    if (!has_gun) {
        static const Animation result{
            std::array{
                       textures::player_idle_back[0],
                       textures::player_idle_back[0],
                       textures::player_idle_back[0],

                       textures::player_idle_back[1],
                       textures::player_idle_back[1],
                       textures::player_idle_back[1],
                       textures::player_idle_back[1],
                       textures::player_idle_back[1],
                       textures::player_idle_back[1],
                       textures::player_idle_back[1],

                       textures::player_idle_back[0],
                       textures::player_idle_back[0],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
    else {
        static const Animation result{
            std::array{
                       textures::player_back_with_weapon[0],
                       textures::player_back_with_weapon[0],
                       textures::player_back_with_weapon[0],

                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],
                       textures::player_back_with_weapon[1],

                       textures::player_back_with_weapon[0],
                       textures::player_back_with_weapon[0],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
}

auto run_animation_front(const bool has_gun) noexcept -> const Animation&
{
    static const unsigned id{generate_id()};

    if (!has_gun) {
        static const Animation result{
            std::array{
                       textures::player_idle[0],
                       textures::player_idle[0],
                       textures::player_idle[0],

                       textures::player_move[0],
                       textures::player_move[0],
                       textures::player_move[0],

                       textures::player_idle[0],
                       textures::player_idle[0],
                       textures::player_idle[0],

                       textures::player_move[1],
                       textures::player_move[1],
                       textures::player_move[1],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
    else {
        static const Animation result{
            std::array{
                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],

                       textures::player_move_gun[0],
                       textures::player_move_gun[0],
                       textures::player_move_gun[0],

                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],
                       textures::player_with_weapon[0],

                       textures::player_move_gun[1],
                       textures::player_move_gun[1],
                       textures::player_move_gun[1],
                       },
            id,
            sf::Vector2f{ 32, 32 },
            Animation::FaceDirection::eRight
        };

        return result;
    }
}

auto run_animation_back(const bool has_gun) noexcept -> const Animation&
{
    return idle_animation_back(has_gun);
}
