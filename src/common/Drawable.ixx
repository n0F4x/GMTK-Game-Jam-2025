module;

#include <SFML/System/Vector2.hpp>

export module common.Drawable;

import core.assets.Handle;
import common.Textures;

export struct Drawable {
    // pls make all textures be part of one atlas.
    Textures::Texture texture;

    // Size of the drawable on-screen.
    sf::Vector2f size{ 1, 1 };

    // which layer this should be on.
    // larger number means higher priority. (range: -10 < x < 10)
    int layer = 0;
};
