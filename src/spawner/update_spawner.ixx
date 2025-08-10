export module spawner.update_spawner;

import ddge.modules.scheduler;

import spawner.tick_spawner;

export inline const auto update_spawner = ddge::scheduler::start_as(tick_spawner);
