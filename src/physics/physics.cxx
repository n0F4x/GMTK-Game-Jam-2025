module;

#include <optional>

#include <SFML/System/Vector2.hpp>

module physics.physics;

import components.Position;
import components.Moveable;
import components.MovementSpeed;
import components.Position;
import physics.collider;

auto physics::move_moveables(
    Registry                       registry,
    Query<Position, Hitbox, Solid> solids_query
) -> void
{
    core::ecs::query(
        registry.get(),
        [solids_query](
            Position&                                position,
            const core::ecs::Optional<Hitbox>        hitbox,
            Moveable&                                moveable,
            const core::ecs::Optional<MovementSpeed> max_speed
        ) {
            if (moveable.velocity == sf::Vector2f{}) {
                return;
            }

            sf::Vector2f velocity = moveable.velocity;
            if (max_speed.has_value()) {
                const float square = max_speed->underlying() * max_speed->underlying();
                if (velocity.lengthSquared() > square) {
                    velocity = velocity.normalized() * max_speed->underlying();
                }
            }

            sf::Vector2f nextPos = position.underlying() + velocity;

            if (hitbox.has_value()) {
                solids_query.for_each(
                    [&nextPos,
                     hitbox](const Position solid_pos, const Hitbox solid_hitbox, Solid) {
                        auto update = physics::collision_check(
                            nextPos, *hitbox, solid_pos.underlying(), solid_hitbox
                        );
                        nextPos = nextPos + update;
                    }
                );
            }

            // update this moveable
            moveable.lastStep     = nextPos - position.underlying();
            position.underlying() = nextPos;
        }
    );
}
