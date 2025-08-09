module;

#include <optional>
#include <vector>

#include <SFML/System/Vector2.hpp>

export module states.GlobalState;

import modules.scheduler.accessors.resources.Resource;
import window.Window;
import modules.ecs;
import modules.assets;

using namespace modules::scheduler::accessors;
using namespace window;

export struct GlobalState {
    modules::ecs::ID player_id{};
    sf::Vector2f  camera_position{};

    // smaller value more you see, larger value more zooom
    // zoom = 1 ~ around 2 tiles height
    float zoom = 0.15f;

    auto worldSpaceCursor(Resource<Window> window) const -> std::optional<sf::Vector2f>;

    std::vector<modules::assets::Handle<std::string>> levels;
    std::vector<modules::assets::Handle<std::string>> level_spawners;
    int                                            current_level_index = 0;
    modules::ecs::ID                                  tile_array[40][40];
};
