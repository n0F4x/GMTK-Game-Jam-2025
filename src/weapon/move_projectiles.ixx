module;
#include <vector>

export module weapon.move_projectiles;

import core.ecs;
import components.Position;
import components.WeaponProjectile;
import extensions.scheduler;
using namespace extensions::scheduler::accessors::ecs;

export auto move_projectiles(
    Registry&                                              registry,
    const Query<core::ecs::ID, Position, WeaponProjectile> entities
)
{
    std::vector<core::ecs::ID> toRemove;

    entities.for_each(
        [&toRemove](
            core::ecs::ID id, Position& position, WeaponProjectile& projectile
        ) -> void {
            position->x += projectile.direction.x * projectile.speed;
            position->y += projectile.direction.y * projectile.speed;
            projectile.range -= projectile.speed;
            if (projectile.range <= 0) {
                toRemove.push_back(id);
            }
        }
    );

    for (const auto& id : toRemove) {
        registry->destroy(id);
    }
}
