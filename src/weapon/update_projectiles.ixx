export module weapon.move_projectiles;

import ddge.modules.ecs;
import ddge.modules.scheduler;

import components.Position;
import components.MovementSpeed;
import components.WeaponProjectile;
import components.Hitbox;
import components.AttackAttributes;
import components.Health;
import components.Solid;

using namespace ddge::scheduler::accessors;

namespace weapon {

export auto update_projectiles(
    Registry                                                             registry,
    Query<ddge::ecs::ID, Position, AttackAttributes, WeaponProjectile>&  projectiles,
    Query<ddge::ecs::ID, Position, Hitbox, ddge::ecs::Optional<Health>>& other_entities
) -> void;

}   // namespace weapon
