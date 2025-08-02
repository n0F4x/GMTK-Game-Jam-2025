//
// Created by kosmx on 2025-07-31.
//

module;

#include <SFML/Graphics/Shader.hpp>

export module states.Shaders;

import core.assets;

export struct Shaders {
    core::assets::Handle<sf::Shader> generic_draw;
};
