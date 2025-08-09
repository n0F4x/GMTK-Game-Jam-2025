export module player.create_player;

import modules.scheduler;

import states.GlobalState;

using namespace modules::scheduler::accessors;

export auto create_player(Registry registry, State<GlobalState> globalState) -> void;
