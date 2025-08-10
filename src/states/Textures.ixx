module;

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

export module states.Textures;

import ddge.modules.assets;

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

    ddge::assets::Handle<sf::Texture> atlas;
    ddge::assets::Handle<sf::Texture> overworld_dialog;
    ddge::assets::Handle<sf::Texture> hell_dialog;
};
