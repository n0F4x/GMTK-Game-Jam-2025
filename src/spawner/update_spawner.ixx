export module spawner.update_spawner;

import spawner.tick_spawner;
import extensions.scheduler;

export inline const auto update_spawner = extensions::scheduler::start_as(tick_spawner);
