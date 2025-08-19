export module player.move_player;

import ddge.modules.execution;

import states.GlobalState;

using namespace ddge::exec::accessors;

export auto move_player(Registry registry, State<GlobalState> global_state) -> void;
