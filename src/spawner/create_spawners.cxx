module;

#include <SFML/System/Vector2.hpp>

module spawner.create_spawners;

import extensions.scheduler;

import components.Spawner;
import components.Position;

using namespace extensions::scheduler::accessors;

auto create_spawners(const Registry registry) -> void
{
    registry->create(Spawner { .isActive = true, .remainingSpawns = 5 }, Position { sf::Vector2f {10, 10} });
}
