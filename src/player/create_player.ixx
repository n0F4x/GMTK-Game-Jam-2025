export module player.create_player;

import extensions.scheduler;
import common.GlobalState;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::states;

export auto create_player(Registry registry, State<GlobalState> globalState) -> void;
