export module enemy.move_enemy;

import ddge.modules.execution;

import states.GlobalState;

using namespace ddge::exec::accessors;

export auto move_enemy(Registry registry, State<GlobalState> global_state) -> void;
