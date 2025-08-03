module;
#include <vector>

export module logic.destroy_dead_enemies;

import components.Enemy;
import components.Health;
import extensions.scheduler.accessors;
import core.ecs;

using namespace extensions::scheduler::accessors;

export auto destroy_dead_enemies(Registry registry, Query<core::ecs::ID, core::ecs::With<Enemy>, Health> enemies)
{
    std::vector<core::ecs::ID> dead_enemies;
    enemies.for_each([&dead_enemies](core::ecs::ID id, Health health) {
        if (health.underlying() <= 0) {
            dead_enemies.push_back(id);
        }
    });

    for (const auto& id : dead_enemies) {
        registry->destroy(id);
    }
}
