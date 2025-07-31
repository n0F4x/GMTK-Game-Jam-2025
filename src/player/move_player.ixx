//
// Created by gabor on 2025-07-31.
//
module;

#include <print>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

export module player.move_player;

import core.ecs;
import extensions.scheduler;

import player.Player;

using namespace extensions::scheduler::accessors::ecs;

export auto move_player(Registry registry) -> void;

module :private;

auto move_player(const Registry registry) -> void
{
    core::ecs::query(registry.get(), [](sf::Vector2f& position, core::ecs::With<Player>) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            position.x -= 4;
            std::println(
                "Player moved left to position: ({}, {})", position.x, position.y
            );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            position.x += 4;
            std::println(
                "Player moved right to position: ({}, {})", position.x, position.y
            );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            position.y += 4;
            std::println(
                "Player moved down to position: ({}, {})", position.x, position.y
            );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            position.y -= 4;
            std::println("Player moved up to position: ({}, {})", position.x, position.y);
        }
    });
}
