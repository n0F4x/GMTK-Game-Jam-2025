export module player.move_player;

import extensions.scheduler;
import states.GlobalState;

using namespace extensions::scheduler::accessors;

export auto move_player(Registry registry, State<GlobalState> global_state) -> void;
