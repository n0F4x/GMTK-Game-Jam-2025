module;

#include <algorithm>

#include <SFML/System/Vector2.hpp>

module enemy.move_enemy;

import core.events;
import core.ecs;
import core.resources;
import extensions.scheduler;
import utility.containers;

import components.Enemy;
import components.MovementSpeed;
import components.Player;
import components.Position;

using namespace extensions::scheduler::accessors::ecs;

auto move_enemy(const Registry registry, const State<GlobalState> global_state) -> void
{
    const Position player_position =
        registry->get_single<Position>(global_state->player_id);

    core::ecs::query(
        registry.get(),
        [player_position](
            core::ecs::With<Enemy>,
            Position&           enemy_position,
            const MovementSpeed movement_speed
        ) {
            constexpr auto stop_radius = 0.5f;

            const auto diff     = player_position - enemy_position;
            auto       velocity = diff->length() > stop_radius ? diff->normalized()
                                                               : sf::Vector2f{ 0, 0 };

            velocity *=
                std::min(movement_speed.underlying(), diff->length() - stop_radius);
            enemy_position.underlying() += velocity;
        }
    );
}
