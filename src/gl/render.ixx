module;

#include <SFML/Graphics.hpp>


export module gl.render;

import extensions.scheduler.accessors.ecs.Query;
import extensions.scheduler.accessors.resources.Resource;
import extensions.scheduler.accessors.states.State;
import common.Drawable;
import common.Position;
import window.Window;
import common.GlobalState;
import common.Shaders;
import common.Textures;
import gl.VertexBufs;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;
using namespace window;

namespace gl {

export auto init_draw(Resource<VertexBufs>& bufs) -> void;

export auto draw_world(
    Query<Position, Drawable> drawable_query,
    Resource<Window>          window,
    State<GlobalState>        global_state,
    State<Shaders>            shaders,
    State<Textures>           textures,
    const Resource<VertexBufs>&     vertexBufs
) -> void;

export sf::Glsl::Mat4 calculate_MVP(const Window& window, const GlobalState& global_state);
}   // namespace gl

export auto initialize() -> void;

