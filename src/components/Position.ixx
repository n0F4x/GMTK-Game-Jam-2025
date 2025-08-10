module;

#include <memory>

#include <SFML/System/Vector2.hpp>

export module components.Position;

import ddge.utility.meta.type_traits.const_like;
import ddge.utility.meta.type_traits.forward_like;
import ddge.utility.Strong;

/**
 * Entity's position in world-space. A unit {1, 0} is as long as the player is tall.
 * If you want to move the entity, DO NOT UPDATE DIRECTLY! if you update this, the entity
 * will "teleport" ignore all collision checks/etc to move, update Moveable::velocity
 * components
 */
export struct Position : ddge::util::Strong<sf::Vector2f, Position> {
    using Strong::Strong;

    template <typename Self_T>
    constexpr auto operator->(this Self_T& self) noexcept
        -> ddge::util::meta::const_like_t<sf::Vector2f, Self_T>*
    {
        return std::addressof(self.underlying());
    }

    constexpr Position(const float x, const float y) : Position(sf::Vector2f(x, y)) {}
};

export constexpr Position& operator+=(Position& left, Position right)
{
    left.underlying() += right.underlying();
    return left;
}

export [[nodiscard]]
constexpr Position operator-(Position left, Position right)
{
    return Position{ left.underlying() - right.underlying() };
}
