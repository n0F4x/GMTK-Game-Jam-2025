module;

#include <memory>

#include <SFML/System/Vector2.hpp>

export module components.Hitbox;


import ddge.utility.meta.type_traits.const_like;
import ddge.utility.meta.type_traits.forward_like;
import ddge.utility.Strong;

export struct Hitbox : ddge::util::Strong<sf::Vector2f, Hitbox> {
    using Strong::Strong;

    template <typename Self_T>
    constexpr auto operator->(this Self_T& self) noexcept
        -> ddge::util::meta::const_like_t<sf::Vector2f, Self_T>*
    {
        return std::addressof(self.underlying());
    }

    Hitbox() : Hitbox(sf::Vector2f{ 1, 1 }) {}
};

export constexpr Hitbox& operator+=(Hitbox& left, Hitbox right)
{
    left.underlying() += right.underlying();
    return left;
}

export constexpr Hitbox operator-(Hitbox left, Hitbox right)
{
    return Hitbox{ left.underlying() - right.underlying() };
}
