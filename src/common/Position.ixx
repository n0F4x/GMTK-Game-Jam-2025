module;

#include <SFML/System/Vector2.hpp>

export module common.Position;

import utility.Strong;

export struct Position : util::Strong<sf::Vector2f, Position> {
    using Strong::Strong;

    sf::Vector2f& operator->()
    {
        return underlying();
    }
};
