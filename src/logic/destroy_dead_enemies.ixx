module;
#include <vector>

export module logic.destroy_dead_enemies;

import components.Enemy;
import components.Health;
import ddge.modules.scheduler.accessors;
import ddge.modules.ecs;

using namespace ddge::scheduler::accessors;

export auto destroy_dead_enemies(
    const Registry                                        registry,
    Query<ddge::ecs::ID, ddge::ecs::With<Enemy>, Health>& enemies
) -> void
{
    std::vector<ddge::ecs::ID> dead_enemies;
    enemies.for_each([&dead_enemies](ddge::ecs::ID id, Health health) {
        if (health.underlying() <= 0) {
            dead_enemies.push_back(id);
        }
    });

    for (const auto& id : dead_enemies) {
        registry->destroy(id);
    }
}
