module;

#include <SFML/System/Vector2.hpp>

#include <fastgltf/util.hpp>

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
        [&playerPos](core::ecs::With<Player>, const Position& position) {
            playerPos = position.get();
        }
    );

    core::ecs::query(registry.get(), [&playerPos](core::ecs::With<Enemy>, Position& enemy) {
        constexpr auto speed      = 10.f;
        constexpr auto stopRadius = 50.f;

        auto&      enemyPos = enemy.get();
        const auto diff     = playerPos - enemyPos;
        auto       velocity = diff.length() > stopRadius ? diff.normalized() : sf::Vector2f{ 0, 0 };

        velocity *= fastgltf::min(speed, diff.length() - stopRadius);
        enemyPos += velocity;
    });
}
