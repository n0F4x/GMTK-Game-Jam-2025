module;

#include <SFML/System/Vector2.hpp>

export module common.Drawable;

import core.assets.Handle;
import common.Textures;

export struct Drawable {
    // pls make all textures be part of one atlas.
    Textures::Texture texture;

    // Size of the drawable on-screen.
    sf::Vector2f size{ 100, 100 };

    // which layer this should be on.
    // larger number means higher priority. (can be negative)
    int layer = 0;
};
