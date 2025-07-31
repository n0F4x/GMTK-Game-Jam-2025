module;

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

export module enemy.create_enemy;

import enemy.Enemy;
import extensions.scheduler;
import common.TextureLoader;
import common.Position;
import core.assets.Handle;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedTextureLoader = extensions::scheduler::accessors::assets::Cached<TextureLoader>;

export auto create_enemy(const Registry registry, const CachedTextureLoader texture_loader);

module :private;

auto create_enemy(const Registry registry, const CachedTextureLoader texture_loader)
{
    const core::assets::Handle texture_handle{ texture_loader->load("Demon.png") };
    auto enemy_shape = sf::RectangleShape(sf::Vector2f{ 64, 64 });
    enemy_shape.setTexture(texture_handle.get());

    registry->create(Enemy{}, Position{ sf::Vector2f{ 3, 7 } }, enemy_shape);
    registry->create(Enemy{}, Position{ sf::Vector2f{ 1000, -72 } }, enemy_shape);
    registry->create(Enemy{}, Position{ sf::Vector2f{ -300'000, -72'131 } }, enemy_shape);
}
