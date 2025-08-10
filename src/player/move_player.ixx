export module player.move_player;

import ddge.modules.scheduler;

import states.GlobalState;

using namespace ddge::scheduler::accessors;

export auto move_player(Registry registry, State<GlobalState> global_state) -> void;
