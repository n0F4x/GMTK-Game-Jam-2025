module;

export module physics.physics;

import core.ecs;
import extensions.scheduler.accessors.ecs;
import components.Position;
import components.Hitbox;
import components.Solid;

using namespace extensions::scheduler::accessors::ecs;

namespace physics {
export auto cap_velocities(Registry registry) -> void;

export auto move_moveables(Registry registry, Query<Position, Hitbox, Solid> solids_query)
    -> void;
}   // namespace physics

