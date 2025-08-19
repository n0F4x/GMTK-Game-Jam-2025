module;

#include <SFML/System/Vector2.hpp>

export module level.place_home;

import ddge.modules.ecs;
import components.Home;
import components.Drawable;
import components.Position;
import common.textures;
import ddge.modules.execution.accessors;

export auto place_home(ddge::exec::accessors::Registry registry) -> void
{
    registry->create(Home{}, Position{ sf::Vector2f{ 0, -20} },
        Drawable{ .texture = textures::home[0], .size = { 19.2, 10.8 }, .layer = -9});
}
