module;

#include <vector>

module weapon.move_projectiles;

import core.ecs;

import extensions.scheduler;

import components.Position;
import components.WeaponProjectile;

using namespace extensions::scheduler::accessors::ecs;

auto move_projectiles(
    const Registry                                                              registry,
    const Query<core::ecs::ID, Position, WeaponProjectile, const MovementSpeed> entities
) -> void
{
    std::vector<core::ecs::ID> toRemove;

    entities.for_each(
        [&toRemove](
            const core::ecs::ID id,
            Position&           position,
            WeaponProjectile&   projectile,
            const MovementSpeed speed
        ) -> void {
            position->x += projectile.direction.x * speed.underlying();
            position->y += projectile.direction.y * speed.underlying();
            projectile.range -= speed.underlying();
            if (projectile.range <= 0) {
                toRemove.push_back(id);
            }
        }
    );

    for (const auto& id : toRemove) {
        registry->destroy(id);
    }
}
