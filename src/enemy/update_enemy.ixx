export module enemy.update_enemy;

import enemy.move_enemy;
import core.scheduler;

export inline constexpr auto update_enemy = core::scheduler::start_as(move_enemy);
