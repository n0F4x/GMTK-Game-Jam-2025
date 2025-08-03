module;

module enemy.create_enemy;

import extensions.scheduler;

import common.textures;
import components.Drawable;
import components.Enemy;
import components.Health;
import components.Hitbox;
import components.MovementSpeed;
import components.Position;
import components.Velocity;
import components.AttackAttributes;

using namespace extensions::scheduler::accessors;

auto create_enemy(
    const char enemy_type,
    const Registry      registry,
    const Position      position,
    const Health        health,
    const MovementSpeed movement_speed,
    const AttackAttributes attack_attributes
) -> void
{
    switch (enemy_type) {
        case 'D':
            registry->create(Enemy{}, position, Drawable {textures::demon},
                health, movement_speed, attack_attributes, Velocity{}, Hitbox{});
            break;
        default:;
    }
}
