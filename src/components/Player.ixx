module;

#include <chrono>

#include <SFML/System/Vector2.hpp>

export module components.Player;

export struct Player {
    int                                   xp{ 0 };
    sf::Vector2f                          direction{ 1.0f, 0.0f };
    std::chrono::steady_clock::time_point last_firing_time{
        std::chrono::steady_clock::now()
    };
};
