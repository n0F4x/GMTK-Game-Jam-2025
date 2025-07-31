export module player.update_player;

import player.move_player;
import core.scheduler;

export inline constexpr auto update_player = core::scheduler::start_as(move_player);
