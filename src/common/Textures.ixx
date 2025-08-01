module;

#include <SFML/Graphics/Texture.hpp>

export module common.Textures;

import core.assets;

export struct Textures {
    struct Texture {
        // position in pixels
        sf::Vector2i pos;
        // size in pixels
        sf::Vector2i size = { 32, 32 };
    };

    core::assets::Handle<sf::Texture> atlas;
};

namespace Texture {
export constexpr Textures::Texture Demon{
    { 0, 0 }
};

export constexpr Textures::Texture PlayerIdle[2] = { { { 32, 0 } }, { { 2 * 32, 0 } } };

export constexpr Textures::Texture Projectile{
    { 3 * 32, 0 }
};

export constexpr Textures::Texture PlayerBack[2] = { { { 4 * 32, 0 } },
                                                     { { 5 * 32, 0 } } };
}   // namespace Texture
