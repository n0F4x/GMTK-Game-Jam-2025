//
// Created by gabor on 2025-07-31.
//
module;
#include <optional>
#include <print>
#include <span>

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
    util::OptionalRef<Player> player;
    core::ecs::query(
        registry.get(),
        [&player](const core::ecs::ID id, Player& playerComponent) {
            player = playerComponent;
        }
    );

    for (const WindowEvent event : window_event_reader.read()) {
        if (const auto keyPressedEvent = event.getIf<WindowEvent::KeyPressed>();
            keyPressedEvent != nullptr) {
                switch (keyPressedEvent->code) {
                    case sf::Keyboard::Key::A:
                    case sf::Keyboard::Key::Left:
                        // Move player left
                        player->position.x -= 1;
                        std::println("Player moved left to position: ({}, {})",
                                  player->position.x, player->position.y);
                        break;

                    case sf::Keyboard::Key::D:
                    case sf::Keyboard::Key::Right:
                        // Move player right
                        player->position.x += 1;
                        std::println("Player moved right to position: ({}, {})",
                                  player->position.x, player->position.y);
                        break;

                    case sf::Keyboard::Key::S:
                    case sf::Keyboard::Key::Down:
                        // Move player down
                        player->position.y += 1;
                        std::println("Player moved down to position: ({}, {})",
                                  player->position.x, player->position.y);
                        break;

                    case sf::Keyboard::Key::W:
                    case sf::Keyboard::Key::Up:
                        // Move player up
                        player->position.y -= 1;
                        std::println("Player moved up to position: ({}, {})",
                            player->position.x, player->position.y);

                    default:
                        break;
                }
            }
    }
}