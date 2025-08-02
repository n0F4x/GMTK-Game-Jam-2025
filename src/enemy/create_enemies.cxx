module;

#include <SFML/System/Vector2.hpp>

module enemy.create_enemies;

import extensions.scheduler;

import common.Textures;

import components.Drawable;
import components.Enemy;
import components.Health;
import components.MovementSpeed;
import components.Position;

using namespace extensions::scheduler::accessors;

auto create_enemies(const Registry registry) -> void
{
    auto enemy_drawable = Drawable(texture::Demon);

    const auto spawn_enemy =                                                 //
        [&registry, &enemy_drawable](const sf::Vector2f& position) -> void   //
    {                                                                        //
        registry->create(
            Enemy{},
            Position{ position },
            enemy_drawable,
            Health{ 100 },
            MovementSpeed{ 0.05f }
        );
    };

    spawn_enemy(sf::Vector2f{ 7.f, 5.f });
    spawn_enemy(sf::Vector2f{ -5.f, -7.f });
    spawn_enemy(sf::Vector2f{ 14.f, 6.f });
}
