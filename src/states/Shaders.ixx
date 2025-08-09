//
// Created by kosmx on 2025-07-31.
//

module;

#include <SFML/Graphics/Shader.hpp>

export module states.Shaders;

import modules.assets;

export struct Shaders {
    modules::assets::Handle<sf::Shader> generic_draw;
};
