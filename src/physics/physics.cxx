module;

#include <cmath>

#include <SFML/System/Vector2.hpp>

module physics.physics;

import components.Position;
import components.MovementSpeed;
import components.Position;
import components.Velocity;
import physics.collider;
import common.GameTimer;

// because time lib is still junk, i have no better idea.
constexpr auto tick_length = 1/120.f;

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
                if (velocity->lengthSquared() > 0.03f) {
                    velocity = Velocity{ velocity->normalized()
                                         * max_speed->underlying() };
                }
            }

            velocity.underlying() = velocity.underlying().componentWiseMul({tick_length, tick_length});

            sf::Vector2f nextPos;

            if (hitbox.has_value()) {
                const int    count    = std::ceil(velocity.underlying().length() / 0.12);
                if (count == 0) return; // no update

                sf::Vector2f stepSize = velocity.underlying().componentWiseDiv(
                    sf::Vector2f{ static_cast<float>(count), static_cast<float>(count) }
                );
                nextPos = position.underlying();

                for (int i = 0; i < count; i++) {
                    nextPos = nextPos + stepSize;

                    solids_query.for_each(
                        [&nextPos, hitbox](
                            const Position solid_pos, const Hitbox solid_hitbox, Solid
                        ) {
                            auto update = physics::collision_check(
                                nextPos, *hitbox, solid_pos.underlying(), solid_hitbox
                            );
                            nextPos = nextPos + update;
                        }
                    );
                }
            }
            else {
                nextPos = position.underlying() + velocity.underlying();
            }

            // update this moveable
            position.underlying() = nextPos;
        }
    );
}
