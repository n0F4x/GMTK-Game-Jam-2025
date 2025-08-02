export module enemy.move_enemy;

import extensions.scheduler;

import states.GlobalState;

using namespace extensions::scheduler::accessors;

export auto move_enemy(Registry registry, State<GlobalState> global_state) -> void;
