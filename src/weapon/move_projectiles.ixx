module;
#include <ostream>
#include <vector>

export module weapon.move_projectiles;

import core.ecs;
import common.Position;
import weapon.WeaponProjectile;
import extensions.scheduler;
using namespace extensions::scheduler::accessors::ecs;

export auto move_projectiles(Registry& registry, const Query<core::ecs::ID, Position, WeaponProjectile> entities)
{
    std::vector<core::ecs::ID> toRemove;

    entities.for_each([&toRemove](core::ecs::ID id, Position& position, WeaponProjectile& projectile) -> void {
        std::println("Projectile before: {}, speed: {}, position: ({}, {})",
                     projectile.range, projectile.speed, position->x, position->y);
        position->x += projectile.direction.x * projectile.speed;
        position->y += projectile.direction.y * projectile.speed;
        projectile.range -= projectile.speed;
        std::println("Projectile after: {}, speed: {}, position: ({}, {})",
                     projectile.range, projectile.speed, position->x, position->y);
        if (projectile.range <= 0) {
            toRemove.push_back(id);
        }
    });

    for (auto& id : toRemove) {
        registry->destroy(id);
    }
}