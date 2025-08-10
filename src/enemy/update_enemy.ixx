export module enemy.update_enemy;

import ddge.modules.scheduler;

import enemy.move_enemy;

export inline const auto update_enemy = ddge::scheduler::start_as(move_enemy);
