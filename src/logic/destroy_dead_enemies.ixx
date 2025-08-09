module;
#include <vector>

export module logic.destroy_dead_enemies;

import components.Enemy;
import components.Health;
import modules.scheduler.accessors;
import modules.ecs;

using namespace modules::scheduler::accessors;

export auto destroy_dead_enemies(
    const Registry                                        registry,
    Query<modules::ecs::ID, modules::ecs::With<Enemy>, Health>& enemies
) -> void
{
    std::vector<modules::ecs::ID> dead_enemies;
    enemies.for_each([&dead_enemies](modules::ecs::ID id, Health health) {
        if (health.underlying() <= 0) {
            dead_enemies.push_back(id);
        }
    });

    for (const auto& id : dead_enemies) {
        registry->destroy(id);
    }
}
