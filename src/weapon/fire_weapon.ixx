module;

#include <SFML/System/Vector2.hpp>

export module weapon.fire_weapon;

import modules.ecs;
import modules.scheduler;

import states.GlobalState;
import window.Window;
import components.Weapon;
import components.Position;

using namespace modules::scheduler::accessors;

namespace weapon {

/**
 * Checks if the weapon can be fired immediately.
 * fire_weapon does check, but you can use it if your fire logic is expensive.
 * @param weapon
 * @return
 */
bool check_weapon(Weapon& weapon);

/**
 * Just fire a weapon
 * @param registry registry access
 * @param weapon weapon to fire (for projectile info
 * @param owner_id owner id, just to avoid shooting yourself.
 * @return if the weapon was fired. If false, that means the weapon is still on cooldown.
 */
export auto fire_weapon(
    Registry      registry,
    sf::Vector2f  direction,
    modules::ecs::ID owner_id,
    bool          override_check = false
) -> bool;

/**
 * Check (and if needed) shoots the player weapon(s)
 * @param registry
 * @param global
 * @param window
 */
export auto fire_player_weapon(
    Registry                 registry,
    State<GlobalState>       global,
    Resource<window::Window> window
) -> void;
};   // namespace weapon
