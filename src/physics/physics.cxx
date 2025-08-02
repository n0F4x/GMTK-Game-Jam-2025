module;

#include <cassert>

#include <SFML/System/Vector2.hpp>

module physics.physics;

import components.Position;
import components.MovementSpeed;
import components.Position;
import components.Velocity;
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
            Velocity&                                velocity,
            const core::ecs::Optional<MovementSpeed> max_speed
        ) {
            if (velocity == Velocity{}) {
                return;
            }

            if (max_speed.has_value()) {
                const float square = max_speed->underlying() * max_speed->underlying();
                if (velocity->lengthSquared() > square) {
                    velocity = Velocity{ velocity->normalized()
                                         * max_speed->underlying() };
                }
            }

            sf::Vector2f nextPos = position.underlying() + velocity.underlying();

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
            position.underlying() = nextPos;
        }
    );
}
