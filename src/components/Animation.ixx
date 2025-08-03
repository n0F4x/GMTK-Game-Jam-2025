module;

#include <vector>

#include <SFML/System/Vector2.hpp>

export module components.Animation;

import utility.Strong;

import states.Textures;

export struct Animation {
    std::vector<Textures::Texture> textures;
    size_t                         current_texture_index{};

    // the size of a unit square (should be always 32, 32)
    sf::Vector2f drawable_size{ 32, 32 };
    unsigned     id;
};
