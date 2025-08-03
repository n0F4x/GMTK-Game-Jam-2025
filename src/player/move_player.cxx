module;

#include <cassert>
#include <utility>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

module player.move_player;

import core.ecs;

import components.Animation;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Velocity;

import player.animations;

import states.GlobalState;

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

[[nodiscard]]
auto next_animation(const Velocity velocity, const Animation& previous_animation)
    -> const Animation&
{
    const float velocity_y = velocity->y;

    if (velocity_y == 0) {
        if (previous_animation.id() == idle_animation_front().id()
            || previous_animation.id() == idle_animation_back().id())
        {
            return previous_animation;
        }

        if (previous_animation.id() == run_animation_front().id()) {
            return idle_animation_front();
        }

        if (previous_animation.id() == run_animation_back().id()) {
            return idle_animation_back();
        }

        assert(false && "unhandled animation state change");
        return idle_animation_front();
    }

    if (velocity_y > 0) {
        if (previous_animation.id() == run_animation_back().id()) {
            return previous_animation;
        }

        return run_animation_back();
    }

    if (velocity_y < 0) {
        if (previous_animation.id() == run_animation_front().id()) {
            return previous_animation;
        }

        return run_animation_front();
    }

    std::unreachable();
}

auto move_player(const Registry registry, const State<GlobalState> global_state) -> void
{
    const core::ecs::ID player_id{ global_state->player_id };

    Velocity velocity = velocity_from_input();

    registry->get_single<Velocity>(player_id) = velocity;

    Animation& animation = registry->get_single<Animation>(player_id);
    animation            = next_animation(velocity, animation);
}
