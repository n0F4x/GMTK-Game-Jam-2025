export module weapon.move_projectiles;

import extensions.scheduler;

import core.ecs;

import components.Position;
import components.MovementSpeed;
import components.WeaponProjectile;

using namespace extensions::scheduler::accessors;

export auto move_projectiles(
    Registry                                         registry,
    Query<core::ecs::ID, Position, WeaponProjectile, const MovementSpeed> entities
) -> void;
