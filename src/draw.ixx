module;

#include <SFML/Graphics.hpp>

export module draw;

import extensions.scheduler;

import window.Window;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;

export auto draw(
    const Resource<window::Window>                window,
    const Query<sf::Vector2f, sf::RectangleShape> entities
) -> void
{
    entities.for_each([&window](const sf::Vector2f& position, sf::RectangleShape& shape) {
        shape.setPosition(position);
        window->draw(shape);
    });
}
