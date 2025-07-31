module;

#include <print>

#include <SFML/System/Vector2.hpp>

import core.events;
import core.ecs;
import core.resources;
import extensions.scheduler;
import utility.containers;

import common.Position;
import enemy.Enemy;
import player.Player;

module enemy.move_enemy;

using namespace extensions::scheduler::accessors::ecs;

auto move_enemy(const Registry registry) -> void
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
