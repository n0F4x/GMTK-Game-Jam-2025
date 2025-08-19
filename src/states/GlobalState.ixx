module;

#include <optional>
#include <vector>

#include <SFML/System/Vector2.hpp>

export module states.GlobalState;

import ddge.modules.execution.accessors.resources.Resource;
import window.Window;
import ddge.modules.ecs;
import ddge.modules.assets;

using namespace ddge::exec::accessors;
using namespace window;

export struct GlobalState {
    ddge::ecs::ID player_id{};
    sf::Vector2f  camera_position{};

    // smaller value more you see, larger value more zooom
    // zoom = 1 ~ around 2 tiles height
    float zoom = 0.15f;

    auto worldSpaceCursor(Resource<Window> window) const -> std::optional<sf::Vector2f>;

    std::vector<ddge::assets::Handle<std::string>> levels;
    std::vector<ddge::assets::Handle<std::string>> level_spawners;
    int                                            current_level_index = 0;
    ddge::ecs::ID                                  tile_array[40][40];
};
