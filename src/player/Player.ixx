module;

#include <chrono>

#include <SFML/System/Vector2.hpp>

export module player.Player;

export struct Player {
    int health{ 100 };
    int xp{0};
    float movement_speed{ 0.1f };
    sf::Vector2f direction{ 1.0f, 0.0f };
    std::chrono::steady_clock::time_point last_firing_time{ std::chrono::steady_clock::now() };
};
