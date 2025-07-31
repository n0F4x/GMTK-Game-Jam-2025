//
// Created by gabor on 2025-07-31.
//
module;

#include <optional>
#include <print>
#include <span>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

export module player.move_player;

import core.events;
import core.ecs;
import core.resources;
import extensions.scheduler;
import utility.containers;

import events.WindowEvent;
import player.Player;

export auto move_player(
    const extensions::scheduler::accessors::events::Reader<WindowEvent>& window_event_reader,
    const extensions::scheduler::accessors::ecs::Registry registry);



module :private;

auto move_player(
    const extensions::scheduler::accessors::events::Reader<WindowEvent>& window_event_reader,
    const extensions::scheduler::accessors::ecs::Registry registry
)
{
    util::OptionalRef<sf::Vector2f> playerPosition;
    core::ecs::query(
        registry.get(),
        [&playerPosition](const core::ecs::ID id, sf::Vector2f& position, core::ecs::With<Player> player) {
            playerPosition = position;
        }
    );

    for (const WindowEvent event : window_event_reader.read()) {
        if (const auto keyPressedEvent = event.getIf<WindowEvent::KeyPressed>();
            keyPressedEvent != nullptr) {
                switch (keyPressedEvent->code) {
                    case sf::Keyboard::Key::A:
                    case sf::Keyboard::Key::Left:
                        // Move player left
                        playerPosition->x -= 4;
                        std::println("Player moved left to position: ({}, {})",
                                  playerPosition->x, playerPosition->y);
                        break;

                    case sf::Keyboard::Key::D:
                    case sf::Keyboard::Key::Right:
                        // Move player right
                        playerPosition->x += 4;
                        std::println("Player moved right to position: ({}, {})",
                                  playerPosition->x, playerPosition->y);
                        break;

                    case sf::Keyboard::Key::S:
                    case sf::Keyboard::Key::Down:
                        // Move player down
                        playerPosition->y += 4;
                        std::println("Player moved down to position: ({}, {})",
                                  playerPosition->x, playerPosition->y);
                        break;

                    case sf::Keyboard::Key::W:
                    case sf::Keyboard::Key::Up:
                        // Move player up
                        playerPosition->y -= 4;
                        std::println("Player moved up to position: ({}, {})",
                            playerPosition->x, playerPosition->y);

                    default:
                        break;
                }
            }
    }
}