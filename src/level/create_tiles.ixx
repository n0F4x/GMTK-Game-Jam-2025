module;

#include <SFML/System/Vector2.hpp>

export module level.create_tiles;

import components.Position;
import components.Tile;
import components.Drawable;
import common.Textures;
import common.GlobalState;
import extensions.scheduler.accessors.ecs.Registry;
import extensions.scheduler.accessors.states.State;

export auto create_tiles(const extensions::scheduler::accessors::Registry& registry,
    extensions::scheduler::accessors::State<GlobalState> global_state)
{
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            auto id = registry->create(Tile{}, Position{ sf::Vector2f{ static_cast<float>(i), static_cast<float>(-j) } },
            Drawable { .texture = textures::nothing, .layer = -9 });
            global_state->tile_array[i][j] = id;
        }
    }
}