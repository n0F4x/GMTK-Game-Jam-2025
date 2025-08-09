export module weapon.move_projectiles;

import modules.ecs;
import modules.scheduler;

import components.Position;
import components.MovementSpeed;
import components.WeaponProjectile;
import components.Hitbox;
import components.AttackAttributes;
import components.Health;
import components.Solid;

using namespace modules::scheduler::accessors;

namespace weapon {

export auto update_projectiles(
    Registry                                                             registry,
    Query<modules::ecs::ID, Position, AttackAttributes, WeaponProjectile>&  projectiles,
    Query<modules::ecs::ID, Position, Hitbox, modules::ecs::Optional<Health>>& other_entities
) -> void;

}   // namespace weapon
