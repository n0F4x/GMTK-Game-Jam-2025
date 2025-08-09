export module enemy.move_enemy;

import modules.scheduler;

import states.GlobalState;

using namespace modules::scheduler::accessors;

export auto move_enemy(Registry registry, State<GlobalState> global_state) -> void;
