module;

#include <optional>

#include <SFML/System/Vector2.hpp>

export module physics.collider;

import components.Position;
import components.Hitbox;

namespace physics {

/**
 * check collision between two entities.
 *
 * I have no f*** clue how it works, I wrote this algorithm 4 years ago...
 * But I remember that it works well if there is a line of solid objects and an entity
 * tries to move towards that but not directly. It will just slide properly.
 *
 * @param entity_pos position of entity A
 * @param entity_hitbox hitbox of entity A
 * @param other_pos position of entity B
 * @param other_hitbox hitbox of entity B
 * @return how much entity A has to be moved (and what direction) to avoid collision
 * between A and B. (zero vector if there is no collision)
 */
export auto collision_check(
    sf::Vector2f entity_pos,
    Hitbox       entity_hitbox,
    sf::Vector2f other_pos,
    Hitbox       other_hitbox
) -> sf::Vector2f;
}   // namespace physics
