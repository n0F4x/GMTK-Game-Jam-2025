export module initialize;

import core.scheduler;
import window.initialize;
import player.create_player;

export inline constexpr auto initialize = core::scheduler::start_as(window::initialize)
    .then(create_player);
