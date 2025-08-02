module;

#include <vector>

#include <SFML/System/Vector2.hpp>

module weapon.move_projectiles;

import core.ecs;

import extensions.scheduler;

import components.Position;
import components.WeaponProjectile;
import physics.collider;

using namespace extensions::scheduler::accessors;

auto weapon::update_projectiles(
    Registry                                                            registry,
    Query<core::ecs::ID, Position, AttackAttributes, WeaponProjectile>  projectiles,
    Query<core::ecs::ID, Position, Hitbox, core::ecs::Optional<Health>> other_entities
) -> void
{
    std::vector<core::ecs::ID> toRemove;

    projectiles.for_each(
        [&toRemove, &other_entities](
            const core::ecs::ID id,
            Position&           position,
            AttackAttributes&   attributes,
            WeaponProjectile&   projectile
        ) -> void {
            bool remove = false;

            other_entities.for_each([&remove, id, &attributes, projectile, position](
                                        core::ecs::ID               entity_ID,
                                        Position                    entity_pos,
                                        Hitbox                      entity_hitbox,
                                        core::ecs::Optional<Health> maybe_health
                                    ) {
                auto collision = physics::collision_check(
                    position.underlying(),
                    Hitbox{
                        sf::Vector2f{ .4, .4 }
                },
                    entity_pos.underlying(),
                    entity_hitbox
                );
                if (projectile.owner_id == entity_ID) {
                    return;
                }

                if (collision != sf::Vector2f{}) {
                    remove = true;
                    if (maybe_health.has_value()) {
                        // damage
                        maybe_health->underlying() -= attributes.roll_damage();
                    }
                }
            });

            if (remove) {
                toRemove.push_back(id);
            }
        }
    );

    for (const auto& id : toRemove) {
        registry->destroy(id);
    }
}
