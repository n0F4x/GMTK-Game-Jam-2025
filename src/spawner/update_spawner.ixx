export module spawner.update_spawner;

import spawner.tick_spawner;
import core.scheduler;

export inline constexpr auto update_spawner = core::scheduler::start_as(tick_spawner);
