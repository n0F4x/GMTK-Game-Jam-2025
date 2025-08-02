module;

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

import core.ecs;

import components.MovementSpeed;
import components.Player;
import components.Position;

module player.move_player;

using namespace extensions::scheduler::accessors::ecs;

auto move_player(const Registry registry) -> void
{
    core::ecs::query(
        registry.get(),
        [](Position& position, Player& player, const MovementSpeed movement_speed) {
            sf::Vector2f movement;
            sf::Vector2f direction;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                movement.x -= 1;
                direction = sf::Vector2f{ -1, 0 };
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            {
                movement.x += 1;
                direction = sf::Vector2f{ 1, 0 };
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                movement.y -= 1;
                direction = sf::Vector2f{ 0, -1 };
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                movement.y += 1;
                direction = sf::Vector2f{ 0, 1 };
            }

            if (movement.x != 0 || movement.y != 0) {
                movement = movement.normalized() * movement_speed.underlying();
            }

            position.underlying() += movement;

            if (direction != sf::Vector2f{ 0, 0 }) {
                player.direction = direction;
            }
        }
    );
}
