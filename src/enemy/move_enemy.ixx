export module enemy.move_enemy;

import ddge.modules.scheduler;

import states.GlobalState;

using namespace ddge::scheduler::accessors;

export auto move_enemy(Registry registry, State<GlobalState> global_state) -> void;
