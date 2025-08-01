module;

#include <optional>

#include <SFML/System/Vector2.hpp>

export module common.GlobalState;

import extensions.scheduler.accessors.resources.Resource;
import window.Window;
import core.ecs;


using namespace extensions::scheduler::accessors::resources;
using namespace window;

export struct GlobalState {
    core::ecs::ID player_id{};
    sf::Vector2f  camera_position{};

    // smaller value more you see, larger value more zooom
    // zoom = 1 ~ around 2 tiles height
    float zoom = 0.15f;

    auto worldSpaceCursor(Resource<Window> window) const -> std::optional<sf::Vector2f>;
};
