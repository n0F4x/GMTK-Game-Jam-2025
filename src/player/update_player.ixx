export module player.update_player;

import ddge.modules.scheduler;

import player.move_player;

export inline const auto update_player = ddge::scheduler::start_as(move_player);
