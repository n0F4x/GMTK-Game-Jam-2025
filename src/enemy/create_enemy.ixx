module;

#include <SFML/System/Vector2.hpp>

export module enemy.create_enemy;

import enemy.Enemy;
import extensions.scheduler;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

export auto create_enemy(const Registry registry);

module :private;

auto create_enemy(const Registry registry)
{
    registry->create(Enemy{}, sf::Vector2f{ 3, 7 });
    registry->create(Enemy{}, sf::Vector2f{ 1'000, -72 });
    registry->create(Enemy{}, sf::Vector2f{ -300'000, -72'131 });
}
