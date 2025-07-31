module;

#include <vector>

#include <SFML/Graphics/Texture.hpp>

export module common.Textures;

import core.assets;

export struct Textures {
    std::vector<core::assets::Handle<sf::Texture>> textures;
};
