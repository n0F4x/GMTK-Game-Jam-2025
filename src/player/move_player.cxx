module;

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

module player.move_player;

import core.ecs;

import common.GlobalState;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Velocity;

using namespace extensions::scheduler::accessors;

[[nodiscard]]
auto velocity_from_input() -> Velocity
{
    Velocity result;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        result->x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        result->x += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        result->y -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        result->y += 1;
    }

    return result;
}

auto move_player(const Registry registry, const State<GlobalState> global_state) -> void
{
    Velocity velocity = velocity_from_input();

    registry->get_single<Velocity>(global_state->player_id) = velocity;

    if (velocity->x != 0) {
        velocity->y = 0;
    }
    else if (velocity->y == 0) {
        velocity->x = 1;
    }

    registry->get_single<Player>(global_state->player_id).direction = velocity.underlying(
    );
}
