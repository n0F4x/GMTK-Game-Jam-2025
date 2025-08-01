module;

#include <SFML/System/Vector2.hpp>

export module common.GlobalState;

import core.ecs;

export struct GlobalState {
    core::ecs::ID player_id{};
    sf::Vector2f camera_position{};
    sf::Vector2f camera_zoom{};
};
