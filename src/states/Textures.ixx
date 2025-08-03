module;

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

export module states.Textures;

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
