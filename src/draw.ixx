module;

#include <SFML/Graphics.hpp>

export module draw;

import extensions.scheduler;

import window.Window;

export auto draw_shapes(
    extensions::scheduler::accessors::resources::Resource<window::Window> window,
    extensions::scheduler::accessors::ecs::Query<sf::Vector2f, sf::RectangleShape> entities)
{
    entities.for_each([&window](const sf::Vector2f& position, sf::RectangleShape& shape) {
        shape.setPosition(position);
        window->draw(shape);
    });
}
