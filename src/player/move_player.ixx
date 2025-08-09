export module player.move_player;

import modules.scheduler;

import states.GlobalState;

using namespace modules::scheduler::accessors;

export auto move_player(Registry registry, State<GlobalState> global_state) -> void;
