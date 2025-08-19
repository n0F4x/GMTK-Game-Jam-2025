export module spawner.update_spawner;

import ddge.modules.execution;

import spawner.tick_spawner;

export inline const auto update_spawner = ddge::exec::start_as(tick_spawner);
