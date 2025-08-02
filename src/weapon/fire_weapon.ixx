module;

#include <chrono>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

export module weapon.fire_weapon;

import common.Position;
import weapon.Weapon;
import weapon.WeaponProjectile;
import player.Player;
import core.ecs;
import extensions.scheduler;
import common.Drawable;
import common.Textures;

auto spawn_projectile(extensions::scheduler::accessors::ecs::Registry registry,
    const Position& playerPos, const Player& player, const Weapon& weapon)
{
    auto projectilePos = playerPos.get();
    projectilePos += player.direction.normalized() * 0.5f;

    registry->create(WeaponProjectile{
        .damage = weapon.damage,
        .range = weapon.range,
        .speed = weapon.projectile_speed,
        .direction = sf::Vector2f{ player.direction.x, player.direction.y }
    }, Position{projectilePos},
    Drawable{ .texture = Texture::Projectile, .size = {0.25f, 0.25f}});
}

export auto fire_weapon(const extensions::scheduler::accessors::ecs::Registry registry)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        core::ecs::query(
            registry.get(),
            [&](const Position& playerPos, Player& player, Weapon& weapon) {
                auto now = std::chrono::steady_clock::now();
                if (now - player.last_firing_time > std::chrono::milliseconds{ weapon.firing_rate_ms }) {
                    player.last_firing_time = now;
                    spawn_projectile(registry, playerPos, player, weapon);
                }
            }
        );
    }
}
