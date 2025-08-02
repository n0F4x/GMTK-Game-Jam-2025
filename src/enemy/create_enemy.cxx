module;

module enemy.create_enemy;

import extensions.scheduler;

import common.Textures;

import components.Drawable;
import components.Enemy;
import components.Health;
import components.Hitbox;
import components.MovementSpeed;
import components.Position;
import components.Velocity;

using namespace extensions::scheduler::accessors;

auto create_enemy(
    const Registry      registry,
    const Position      position,
    const Health        health,
    const MovementSpeed movement_speed
) -> void
{
    auto enemy_drawable = Drawable(textures::demon);

    registry->create(
        Enemy{}, position, enemy_drawable, health, movement_speed, Velocity{}, Hitbox{}
    );
}
