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
import components.Velocity;

using namespace extensions::scheduler::accessors;

auto move_enemy(const Registry registry, const State<GlobalState> global_state) -> void
{
    const Position player_position =
        registry->get_single<Position>(global_state->player_id);

    core::ecs::query(
        registry.get(),
        [player_position](
            core::ecs::With<Enemy>, Velocity& velocity, const Position enemy_position
        ) {
            constexpr static auto stop_radius = 0.5f;

            const auto diff = player_position - enemy_position;
            velocity = diff->length() > stop_radius ? Velocity{ diff->normalized() }
                                                    : Velocity{};

            velocity *= diff->length() - stop_radius;
        }
    );
}
