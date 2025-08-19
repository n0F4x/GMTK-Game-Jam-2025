export module player.update_player;

import ddge.modules.execution;

import player.move_player;

export inline const auto update_player = ddge::exec::start_as(move_player);
