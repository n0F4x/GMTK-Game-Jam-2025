module;

#include<SFML/Graphics.hpp>

export module player.follow_player;

import modules.scheduler.accessors.ecs.Registry;
import modules.scheduler.accessors.states.State;

import components.Position;
import components.Player;
import states.GlobalState;

export auto follow_player(const modules::scheduler::accessors::Registry& registry,
    modules::scheduler::accessors::State<GlobalState> global_state) -> void
{
    if (!global_state.has_value()) {
        return;
    }

    sf::Vector2f player_position = registry->get_single<Position>(global_state->player_id).underlying();
    auto camera_position = global_state->camera_position;
    auto diff = player_position - camera_position;

    global_state->camera_position += diff * 0.05f;
}
