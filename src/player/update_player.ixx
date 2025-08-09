export module player.update_player;

import modules.scheduler;

import player.move_player;

export inline const auto update_player = modules::scheduler::start_as(move_player);
