module;

#include <chrono>
#include <print>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

export module weapon.fire_weapon;

import common.Position;
import weapon.Weapon;
import weapon.WeaponProjectile;
import player.Player;
import core.ecs;
import common.TextureLoader;
import core.assets.Handle;
import extensions.scheduler;

using CachedTextureLoader =
    extensions::scheduler::accessors::assets::Cached<TextureLoader>;

auto spawn_projectile(extensions::scheduler::accessors::ecs::Registry registry,
    const CachedTextureLoader texture_loader,
    const Position& playerPos, const Player& player, const Weapon& weapon)
{
    const core::assets::Handle texture_handle{ texture_loader->load("Ammo.png") };
    auto ammo_shape = sf::RectangleShape(sf::Vector2f{ 16, 16 });
    ammo_shape.setTexture(texture_handle.get());

    registry->create(WeaponProjectile{
        .damage = weapon.damage,
        .range = weapon.range,
        .speed = weapon.projectile_speed,
        .direction = sf::Vector2f{ player.direction.x, player.direction.y }
    }, Position{ sf::Vector2f{playerPos->x, playerPos->y} }, ammo_shape);
}

export auto fire_weapon(const extensions::scheduler::accessors::ecs::Registry registry,
    CachedTextureLoader texture_loader)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        core::ecs::query(
            registry.get(),
            [&](const Position& playerPos, Player& player, const Weapon& weapon) {
                auto now = std::chrono::steady_clock::now();
                if (now - player.last_firing_time > std::chrono::milliseconds{ weapon.firing_rate_ms }) {
                    player.last_firing_time = now;
                    spawn_projectile(registry, texture_loader, playerPos, player, weapon);
                }
            }
        );
    }
}
