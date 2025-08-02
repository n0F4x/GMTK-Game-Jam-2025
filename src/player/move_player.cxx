module;

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

import core.ecs;

import common.GlobalState;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Moveable;

module player.move_player;

using namespace extensions::scheduler::accessors;

auto checkInput()
{
    sf::Vector2f movement;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        movement.x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        movement.x += 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        movement.y -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        movement.y += 1;
    }

    return movement;

}

auto move_player(const Registry registry, State<GlobalState> global_state) -> void
{
    sf::Vector2f mov = checkInput();

    Moveable& player_vecolity = registry->get_single<Moveable>(global_state->player_id);
    Player& player = registry->get_single<Player>(global_state->player_id);

    player_vecolity.velocity = mov;

    if (mov.x != 0) {
        mov.y = 0;
    } else if (mov.y == 0) {
        mov.x = 1;
    }
    player.direction = mov;
}
