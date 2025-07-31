export module initialize;

import core.scheduler;
import window.initialize;
import common.load_textures;
import player.create_player;

export inline constexpr auto initialize =
    core::scheduler::start_as(window::initialize)   //
        .then(load_textures)
        .then(create_player);
