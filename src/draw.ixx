module;

#include <SFML/Graphics.hpp>

export module draw;

import extensions.scheduler;
import common.Position;

import window.Window;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;

export auto draw(
    const Resource<window::Window>                window,
    const Query<Position, sf::RectangleShape> entities
) -> void
{
    entities.for_each([&window](const Position& position, sf::RectangleShape& shape) {
        shape.setPosition(position.underlying());
        window->draw(shape);
    });
}
