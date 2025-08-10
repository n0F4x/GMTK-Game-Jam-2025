module;

#include<SFML/Graphics.hpp>

export module player.follow_player;

import ddge.modules.scheduler.accessors.ecs.Registry;
import ddge.modules.scheduler.accessors.states.State;

import components.Position;
import components.Player;
import states.GlobalState;

export auto follow_player(const ddge::scheduler::accessors::Registry& registry,
    ddge::scheduler::accessors::State<GlobalState> global_state) -> void
{
    if (!global_state.has_value()) {
        return;
    }

    sf::Vector2f player_position = registry->get_single<Position>(global_state->player_id).underlying();
    auto camera_position = global_state->camera_position;
    auto diff = player_position - camera_position;

    global_state->camera_position += diff * 0.05f;
}
