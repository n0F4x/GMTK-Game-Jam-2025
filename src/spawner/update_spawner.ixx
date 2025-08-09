export module spawner.update_spawner;

import modules.scheduler;

import spawner.tick_spawner;

export inline const auto update_spawner = modules::scheduler::start_as(tick_spawner);
