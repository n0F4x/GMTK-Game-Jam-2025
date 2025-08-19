module;

module enemy.create_enemy;

import ddge.modules.execution;

import common.textures;
import components.Drawable;
import components.Enemy;
import components.Health;
import components.Hitbox;
import components.MovementSpeed;
import components.Position;
import components.Velocity;
import components.AttackAttributes;

using namespace ddge::exec::accessors;

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
            registry->create(Enemy{}, position, Drawable {textures::demon_idle},
                health, movement_speed, attack_attributes, Velocity{}, Hitbox{});
            break;
        default:;
    }
}
