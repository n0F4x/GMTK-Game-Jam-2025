module;

#include<string>

export module enemy.create_enemy;

import ddge.modules.execution;

import components.Health;
import components.MovementSpeed;
import components.Position;
import components.AttackAttributes;

using namespace ddge::exec::accessors;

export auto create_enemy(
    const char enemy_type,
    const Registry      registry,
    const Position      position,
    const Health        health,
    const MovementSpeed movement_speed,
    const AttackAttributes attack_attributes
) -> void;
