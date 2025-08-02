export module weapon.move_projectiles;

import extensions.scheduler;

import core.ecs;

import components.Position;
import components.MovementSpeed;
import components.WeaponProjectile;
import components.Hitbox;
import components.AttackAttributes;
import components.Health;
import components.Solid;

using namespace extensions::scheduler::accessors;

namespace weapon {
export auto update_projectiles(
    Registry                                                            registry,
    Query<core::ecs::ID, Position, AttackAttributes, WeaponProjectile>  projectiles,
    Query<core::ecs::ID, Position, Hitbox, core::ecs::Optional<Health>> other_entities
) -> void;
}   // namespace weapon
