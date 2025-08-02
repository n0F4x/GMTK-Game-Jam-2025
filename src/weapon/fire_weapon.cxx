module;

#include <chrono>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

module weapon.fire_weapon;

import core.ecs;

import extensions.scheduler;

import common.Textures;

import components.Drawable;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Weapon;
import components.WeaponProjectile;

using namespace extensions::scheduler::accessors;

auto spawn_projectile(
    const Registry  registry,
    const Position& playerPos,
    const Player&   player,
    const Weapon&   weapon
) -> void
{
    auto projectile_position = playerPos;
    projectile_position += Position{ player.direction.normalized() * 0.5f };

    registry->create(
        WeaponProjectile{
            .damage    = weapon.damage,
            .range     = weapon.range,
            .direction = sf::Vector2f{ player.direction.x, player.direction.y }
    },
        Position{ projectile_position },
        Drawable{ .texture = textures::projectile, .size = { 0.25f, 0.25f } },
        MovementSpeed{ weapon.projectile_speed }
    );
}

auto fire_weapon(const Registry registry) -> void
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        core::ecs::query(
            registry.get(),
            [&](const Position& playerPos, Player& player, Weapon& weapon) {
                auto now = std::chrono::steady_clock::now();
                if (now - player.last_firing_time
                    > std::chrono::milliseconds{ weapon.firing_rate_ms })
                {
                    player.last_firing_time = now;
                    spawn_projectile(registry, playerPos, player, weapon);
                }
            }
        );
    }
}
