module;

#include <SFML/System/Vector2.hpp>

export module enemy.create_enemy;

import enemy.Enemy;
import extensions.scheduler;
import common.TextureLoader;
import common.Position;
import core.assets.Handle;
import common.Textures;
import common.Drawable;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedTextureLoader = extensions::scheduler::accessors::assets::Cached<TextureLoader>;

export auto create_enemy(const Registry registry, const CachedTextureLoader texture_loader);

module :private;

auto create_enemy(const Registry registry, const CachedTextureLoader texture_loader)
{
    auto enemy_shape = Drawable(Texture::Demon);

    registry->create(Enemy{}, Position{ sf::Vector2f{ 30, 70 } }, enemy_shape);
    registry->create(Enemy{}, Position{ sf::Vector2f{ 1000, -72 } }, enemy_shape);
    registry->create(Enemy{}, Position{ sf::Vector2f{ -300, -721 } }, enemy_shape);
}
