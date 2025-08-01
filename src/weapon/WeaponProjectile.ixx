module;

#include <SFML/System/Vector2.hpp>

export module weapon.WeaponProjectile;

export struct WeaponProjectile {
    float damage;
    float range;
    float speed;
    sf::Vector2f direction;
};