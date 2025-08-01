module;

#include <SFML/System/Vector2.hpp>

export module enemy.create_enemy;

import enemy.Enemy;
import extensions.scheduler;
import common.Position;
import common.Textures;
import common.Drawable;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

export auto create_enemy(const Registry registry);

module :private;

auto create_enemy(const Registry registry)
{
    auto enemy_drawable = Drawable(Texture::Demon);

    registry->create(Enemy{}, Position{ sf::Vector2f{ 7.f, 5.f } }, enemy_drawable);
    registry->create(Enemy{}, Position{ sf::Vector2f{ -5.f, -7.f } }, enemy_drawable);
    registry->create(Enemy{}, Position{ sf::Vector2f{ 14.f, 6.f } }, enemy_drawable);
}
