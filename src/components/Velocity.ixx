module;

#include <memory>

#include <SFML/System/Vector2.hpp>

export module components.Velocity;

import ddge.utility.meta.type_traits.const_like;
import ddge.utility.Strong;

export struct Velocity : ddge::util::Strong<sf::Vector2f, Velocity> {
    using Strong::Strong;

    template <typename Self_T>
    constexpr auto operator->(this Self_T& self) noexcept
        -> ddge::util::meta::const_like_t<sf::Vector2f, Self_T>*
    {
        return std::addressof(self.underlying());
    }
};

export constexpr Velocity& operator*=(Velocity& left, float right)
{
    left.underlying() *= right;
    return left;
}
