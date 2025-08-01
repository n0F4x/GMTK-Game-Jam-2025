module;

#include <SFML/System/Vector2.hpp>

export module common.GlobalState;

import core.ecs;

export struct GlobalState {
    core::ecs::ID player_id{};
    sf::Vector2f  camera_position{};

    // smaller value more you see, larger value more zooom
    // zoom = 1 ~ around 2 tiles height
    float zoom = 0.1;
};
