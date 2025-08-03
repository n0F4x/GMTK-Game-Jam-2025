export module enemy.update_enemy;

import enemy.move_enemy;
import extensions.scheduler;

export inline const auto update_enemy = extensions::scheduler::start_as(move_enemy);
