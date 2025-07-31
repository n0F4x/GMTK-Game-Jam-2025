//
// Created by gabor on 2025-07-31.
//

export module player.create_player;

import player.Player;
import extensions.scheduler;
import common.GlobalState;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

export auto create_player(const Registry registry, const State<GlobalState> globalState);

module :private;

auto create_player(const Registry registry, const State<GlobalState> globalState)
{
    Player player;
    player.position = { 0, 0 };

    const auto id = registry->create(player);
    globalState.emplace(GlobalState{ .player_id = id });
}
