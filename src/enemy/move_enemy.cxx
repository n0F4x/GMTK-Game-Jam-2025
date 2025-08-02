module;

#include <algorithm>

#include <SFML/System/Vector2.hpp>

import core.events;
import core.ecs;
import core.resources;
import extensions.scheduler;
import utility.containers;

import components.Position;
import components.Enemy;
import components.Player;

module enemy.move_enemy;

using namespace extensions::scheduler::accessors::ecs;

auto move_enemy(const Registry registry) -> void
{
    sf::Vector2f playerPos;
    core::ecs::query(
        registry.get(),
        [&playerPos](core::ecs::With<Player>, const Position& position) {
            playerPos = position.get();
        }
    );

    core::ecs::query(registry.get(), [&playerPos](core::ecs::With<Enemy>, Position& enemy) {
        constexpr auto speed      = 0.05f;
        constexpr auto stopRadius = 0.5f;

        auto&      enemyPos = enemy.get();
        const auto diff     = playerPos - enemyPos;
        auto       velocity = diff.length() > stopRadius ? diff.normalized()
                                                         : sf::Vector2f{ 0, 0 };

        velocity *= std::min(speed, diff.length() - stopRadius);
        enemyPos += velocity;
    });
}
