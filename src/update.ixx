export module update;

import core.scheduler;

import common.GameTickTimer;
import player.update_player;
import window.update;

export inline constexpr auto update =           //
    core::scheduler::start_as(window::update)   //
        .then(core::scheduler::at_fixed_rate<GameTickTimer>(update_player));
