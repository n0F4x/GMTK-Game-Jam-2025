module;

#include <vector>

#include <SFML/System/Vector2.hpp>

module weapon.move_projectiles;

import modules.ecs;
import modules.scheduler;

import components.Position;
import components.WeaponProjectile;
import physics.collider;

using namespace modules::scheduler::accessors;

auto weapon::update_projectiles(
    Registry                                                             registry,
    Query<modules::ecs::ID, Position, AttackAttributes, WeaponProjectile>&  projectiles,
    Query<modules::ecs::ID, Position, Hitbox, modules::ecs::Optional<Health>>& other_entities
) -> void
{
    std::vector<modules::ecs::ID> toRemove;

    projectiles.for_each(
        [&toRemove, &other_entities](
            const modules::ecs::ID id,
            Position&           position,
            AttackAttributes&   attributes,
            WeaponProjectile&   projectile
        ) -> void {
            bool remove = false;

            other_entities.for_each([&remove, id, &attributes, projectile, position](
                                        modules::ecs::ID               entity_ID,
                                        Position                    entity_pos,
                                        Hitbox                      entity_hitbox,
                                        modules::ecs::Optional<Health> maybe_health
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
