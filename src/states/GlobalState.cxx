module;

#include <iostream>

#include <SFML/Graphics/Transform.hpp>
#include <SFML/Window/Mouse.hpp>

module states.GlobalState;

import modules.scheduler.accessors.resources.Resource;
import window.Window;
import gl.render;

import modules.ecs;

auto GlobalState::worldSpaceCursor(const Resource<Window> window) const
    -> std::optional<sf::Vector2f>
{
    auto windowPos = sf::Vector2f{ sf::Mouse::getPosition(window.get()) };

    auto windowSize = sf::Vector2f{ window->getSize() };
    if (windowPos.x < 0 || windowPos.y < 0 || windowPos.x > windowSize.x
        || windowPos.y > windowSize.y)
    {
        return {};
    }

    // to render space
    windowPos.x /= windowSize.x;
    windowPos.y /= windowSize.y;
    windowPos.x *= 2;
    windowPos.y *= 2;
    windowPos.x -= 1;
    windowPos.y -= 1;
    windowPos.y = -windowPos.y;

    // more translate

    const auto    mvp = gl::calculate_MVP(window.get(), *this);
    sf::Transform t{ mvp.array[0],  mvp.array[1],  mvp.array[3],
                     mvp.array[4],  mvp.array[5],  mvp.array[7],
                     mvp.array[12], mvp.array[13], mvp.array[15] };
    t = t.getInverse();

    auto m_matrix = t.getMatrix();

    auto point = windowPos;

    // damn it SFML matrices
    sf::Vector2f worldPos{ m_matrix[0] * point.x + m_matrix[1] * point.y + m_matrix[3],
                           m_matrix[4] * point.x + m_matrix[5] * point.y + m_matrix[7] };
    return { worldPos };
}
