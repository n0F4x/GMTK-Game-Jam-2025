module;

#include <array>

#include <SFML/Graphics/Texture.hpp>

export module common.Textures;

import core.assets;

export struct Textures {
    struct Texture {
        // position in pixels
        sf::Vector2i pos;
        // size in pixels
        sf::Vector2i size = { 32, 32 };

        constexpr Texture mirror_horizontal() const
        {
            return {
                { pos.x + size.x,  pos.y },
                {        -size.x, size.y }
            };
        }
    };

    core::assets::Handle<sf::Texture> atlas;
};

namespace textures {

export constexpr Textures::Texture demon{
    { 0, 0 }
};

export constexpr std::array player_idle{
    Textures::Texture{ { 32, 0 } },
    Textures::Texture{ { 2 * 32, 0 } },
};

export constexpr Textures::Texture projectile{
    { 3 * 32, 0 }
};

export constexpr std::array player_idle_back{
    Textures::Texture{ { 4 * 32, 0 } },
    Textures::Texture{ { 5 * 32, 0 } },
};

export constexpr Textures::Texture debug_tile{
    { 7 * 32, 0 }
};

export constexpr Textures::Texture vertical_door{
    { 8 * 32, 0 }
};

export constexpr Textures::Texture horizontal_door{
    { 9 * 32, 0 }
};

export constexpr Textures::Texture trapdoor{
    { 10 * 32, 0 }
};

export constexpr Textures::Texture nothing{
        { 127 * 32, 127 * 32 }
};

}   // namespace textures
