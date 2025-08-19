export module enemy.update_enemy;

import ddge.modules.execution;

import enemy.move_enemy;

export inline const auto update_enemy = ddge::exec::start_as(move_enemy);
