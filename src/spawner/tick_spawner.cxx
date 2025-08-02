module spawner.tick_spawner;

import core.ecs;
import extensions.scheduler;

import components.Health;
import components.MovementSpeed;
import components.Position;
import components.Spawner;
import enemy.create_enemy;

using namespace extensions::scheduler::accessors;

auto tick_spawner(const Registry registry) -> void
{
    core::ecs::query(
        registry.get(),
        [registry](Spawner& spawner, const Position& position) {
            if (!spawner.isActive || spawner.remainingSpawns == 0) {
                return;
            }

            create_enemy(registry, position, Health{ 100 }, MovementSpeed{ 0.05f });
            spawner.remainingSpawns--;
        }
    );
}
