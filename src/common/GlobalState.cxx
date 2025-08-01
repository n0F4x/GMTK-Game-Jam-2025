module;

#include <SFML/Graphics/Transform.hpp>
#include <SFML/Window/Mouse.hpp>

module common.GlobalState;

import extensions.scheduler.accessors.resources.Resource;
import window.Window;
import gl.render;

import core.ecs;

auto GlobalState::worldSpaceCursor(const Resource<Window> window) const
    -> std::optional<sf::Vector2f>
{
    auto windowPos = sf::Mouse::getPosition(window.get());

    auto windowSize = sf::Vector2i{ window->getSize() };
    auto diff       = windowPos - windowSize;
    if (diff.x < 0 || diff.y < 0) {
        return {};
    }

    // to render space
    windowPos.x /= windowSize.x;
    windowPos.y /= windowSize.y;

    const auto    mvp = gl::calculate_MVP(window.get(), *this);
    sf::Transform t{ mvp.array[0],  mvp.array[1],  mvp.array[3],
                     mvp.array[4],  mvp.array[5],  mvp.array[7],
                     mvp.array[12], mvp.array[13], mvp.array[15] };
    t = t.getInverse();

    auto worldPos = t.transformPoint(sf::Vector2f{ windowPos });
    return { worldPos };
}
