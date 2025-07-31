module;

#include <print>

#include <SFML/System/Vector2.hpp>

export module enemy.move_enemy;

import core.events;
import core.ecs;
import core.resources;
import extensions.scheduler;
import utility.containers;

import common.Position;
import enemy.Enemy;
import player.Player;

export auto move_enemy(const extensions::scheduler::accessors::ecs::Registry registry);


module :private;

auto move_enemy(const extensions::scheduler::accessors::ecs::Registry registry)
{
    sf::Vector2f playerPos;
    core::ecs::query(
        registry.get(),
        [&playerPos](core::ecs::With<Player>, const sf::Vector2f& position) {
            playerPos = position;
        }
    );

    core::ecs::query(
        registry.get(),
        [&playerPos](const core::ecs::ID id, core::ecs::With<Enemy>, Position& enemy) {
            auto& enemyPos = enemy.underlying();

            const auto diff = playerPos - enemyPos;
            if (diff.length() < 0.005) {
                enemyPos = playerPos;
                return;
            }

            enemyPos += diff / 2.f;
            std::println(
                "Enemy #{} moved to position: ({}, {})",
                id.underlying(),
                enemyPos.x,
                enemyPos.y
            );
        }
    );
}
