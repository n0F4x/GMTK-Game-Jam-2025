module;

#include <SFML/System/Vector2.hpp>

export module level.create_tiles;

import ddge.modules.execution.accessors;

import common.textures;
import components.Position;
import components.Tile;
import components.Drawable;
import states.GlobalState;

export auto create_tiles(
    const ddge::exec::accessors::Registry&    registry,
    ddge::exec::accessors::State<GlobalState> global_state
) -> void
{
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            auto id = registry->create(
                Tile{
            },
                Position{ sf::Vector2f{ static_cast<float>(i), static_cast<float>(-j) } },
                Drawable{ .texture = textures::nothing, .layer = -9 }
            );
            global_state->tile_array[i][j] = id;
        }
    }
}
