export module update;

import core.scheduler;

import common.GameTickTimer;
import player.update_player;
import enemy.update_enemy;
import window.update;

export inline constexpr auto update =           //
    core::scheduler::start_as(window::update)   //
        .then(core::scheduler::at_fixed_rate<GameTickTimer>(update_player))
        .then(core::scheduler::at_fixed_rate<GameTickTimer>(update_enemy));
