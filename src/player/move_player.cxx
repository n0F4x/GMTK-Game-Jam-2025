module;

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

import core.ecs;

import player.Player;
import common.Position;

module player.move_player;

using namespace extensions::scheduler::accessors::ecs;

[[nodiscard]]
auto extra_movement() -> sf::Vector2f
{
    sf::Vector2f result;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        result.x -= 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        result.x += 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        result.y -= 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        result.y += 0.02;
    }

    if (result.x == 0 && result.y == 0) {
        return result;
    }
    else {
        return result.normalized() * 0.02f;
    }



}

auto move_player(const Registry registry) -> void
{
    core::ecs::query(registry.get(), [](Position& position, core::ecs::With<Player>) {
        position.get() += extra_movement();
    });
}
