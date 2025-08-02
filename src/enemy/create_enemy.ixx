export module enemy.create_enemy;

import extensions.scheduler;

import components.Health;
import components.MovementSpeed;
import components.Position;

using namespace extensions::scheduler::accessors;

export auto create_enemy(
    Registry      registry,
    Position      position,
    Health        health,
    MovementSpeed movement_speed
) -> void;
