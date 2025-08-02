module;

#include <SFML/System/Vector2.hpp>

export module components.Player;

export struct Player {
    int          xp{ 0 };
    sf::Vector2f direction{ 1.0f, 0.0f };
};
