module;

#include <vector>

export module components.Animation;

import utility.Strong;

import states.Textures;

export struct Animation {
    std::vector<Textures::Texture> textures;
    size_t                         current_texture_index{};
    unsigned                       id;
};
