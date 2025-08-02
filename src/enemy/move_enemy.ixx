export module enemy.move_enemy;

import extensions.scheduler;

import common.GlobalState;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::states;

export auto move_enemy(Registry registry, State<GlobalState> global_state) -> void;
