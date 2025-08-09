module;

#include <chrono>
#include <tuple>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

module weapon.fire_weapon;

import modules.ecs;
import modules.scheduler;

import common.textures;

import components.Drawable;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Weapon;
import components.WeaponProjectile;
import components.Velocity;
import states.GlobalState;
import components.AttackAttributes;
import window.Window;
import modules.ecs;

using namespace modules::scheduler::accessors;

bool weapon::check_weapon(Weapon& weapon)
{
    if (const auto now = std::chrono::steady_clock::now();
        now - weapon.last_firing_time > std::chrono::milliseconds{ weapon.firing_rate_ms })
    {
        return true;
    }
    return false;
}

auto weapon::fire_weapon(
    Registry      registry,
    sf::Vector2f  direction,
    modules::ecs::ID owner_id,
    bool          override_check
) -> bool
{
    Weapon& weapon = registry->get_single<Weapon>(owner_id);
    if (!override_check && !check_weapon(registry->get_single<Weapon>(owner_id))) {
        return false;
    }

    weapon.last_firing_time = std::chrono::steady_clock::now();

    AttackAttributes& attack_attrs = registry->get_single<AttackAttributes>(owner_id);
    Position          position     = registry->get_single<Position>(owner_id);


    position += Position{ direction.normalized().componentWiseMul({ .5, .5 }) };

    // projectile: Projectile, Position, AttackAttributes, Velocity (no max velocity),
    // Drawable
    registry->create(
        WeaponProjectile(owner_id),
        position,
        attack_attrs,
        Velocity{
            direction.normalized() * weapon.projectile_speed
    },
        Drawable{
            // did not I ask you guys NOT TO DO THIS??? - kosmx
            .texture = textures::projectile,
            .size    = { 0.5f, 0.5f },
        },
        MovementSpeed{ weapon.projectile_speed }
    );
    return true;
}

auto weapon::fire_player_weapon(
    Registry                 registry,
    State<GlobalState>       global_state,
    Resource<window::Window> window
) -> void
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        auto maybe_cursor_pos = global_state->worldSpaceCursor(window);
        if (!maybe_cursor_pos.has_value()) {
            return;
        }

        sf::Vector2f cursor_pos = maybe_cursor_pos.value();
        std::vector<std::tuple<modules::ecs::ID, Position>> toFire{};

        modules::ecs::query(
            registry.get(),
            [&](const modules::ecs::ID owner_id, const Position playerPos, Weapon weapon) {
                if (check_weapon(weapon)) {
                    toFire.emplace_back(owner_id, playerPos);
                }
            }
        );

        for (std::tuple fire : toFire) {
            auto [id, pos]         = fire;
            sf::Vector2f direction = cursor_pos - pos.underlying();
            fire_weapon(registry, direction, id);
        }
    }
}
