export module initialize;

import core.scheduler;
import window.initialize;
import player.create_player;
import enemy.create_enemy;

export inline constexpr auto initialize = core::scheduler::start_as(window::initialize)
    .then(create_player)
    .then(create_enemy);
