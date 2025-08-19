export module player.create_player;

import ddge.modules.execution;

import states.GlobalState;

using namespace ddge::exec::accessors;

export auto create_player(Registry registry, State<GlobalState> globalState) -> void;
