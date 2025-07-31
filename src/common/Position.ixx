module;

#include <memory>

#include <SFML/System/Vector2.hpp>

export module common.Position;

import utility.meta.type_traits.const_like;
import utility.Strong;

export struct Position : util::Strong<sf::Vector2f, Position> {
    using Strong::Strong;

    template <typename Self_T>
    auto operator->(this Self_T& self) noexcept
        -> util::meta::const_like_t<sf::Vector2f, Self_T>*
    {
        return std::addressof(self.underlying());
    }
};
