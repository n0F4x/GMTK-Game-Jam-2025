module;

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

export module states.Textures;

import modules.assets;

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

    modules::assets::Handle<sf::Texture> atlas;
    modules::assets::Handle<sf::Texture> overworld_dialog;
    modules::assets::Handle<sf::Texture> hell_dialog;
};
