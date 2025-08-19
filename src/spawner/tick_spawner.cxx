module spawner.tick_spawner;

import ddge.modules.ecs;
import ddge.modules.execution;

import components.Health;
import components.MovementSpeed;
import components.Position;
import components.Spawner;
import enemy.create_enemy;
import components.AttackAttributes;

using namespace ddge::exec::accessors;

auto tick_spawner(const Registry registry) -> void
{
    ddge::ecs::query(
        registry.get(),
        [registry](Spawner& spawner, const Position& position) {
            if (!spawner.is_active || spawner.remaining_spawns == 0) {
                return;
            }

            create_enemy(spawner.enemy_type, registry, position,
                Health{ spawner.health }, MovementSpeed{ spawner.movement_speed },
                AttackAttributes{ spawner.damage, 0.0f });
            spawner.remaining_spawns--;
        }
    );
}
