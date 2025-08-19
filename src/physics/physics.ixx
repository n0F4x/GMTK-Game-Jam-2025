module;

export module physics.physics;

import ddge.modules.ecs;
import ddge.modules.execution.accessors.ecs;
import components.Position;
import components.Hitbox;
import components.Solid;

using namespace ddge::exec::accessors::ecs;

namespace physics {

export auto move_moveables(Registry registry, Query<Position, Hitbox, Solid>& solids_query)
    -> void;

}   // namespace physics
