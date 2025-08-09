export module enemy.update_enemy;

import modules.scheduler;

import enemy.move_enemy;

export inline const auto update_enemy = modules::scheduler::start_as(move_enemy);
