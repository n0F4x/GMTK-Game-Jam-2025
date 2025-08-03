export module player.update_player;

import player.move_player;
import extensions.scheduler;

export inline const auto update_player = extensions::scheduler::start_as(move_player);
