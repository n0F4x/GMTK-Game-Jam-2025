module;

#include <SFML/System/Vector2.hpp>

export module weapon.WeaponProjectile;

export struct WeaponProjectile {
    float damage{ 0.0f };
    float range{ 0.0f };
    float speed{ 0.0f };
    sf::Vector2f direction{ 0.0f, 0.0f };
};