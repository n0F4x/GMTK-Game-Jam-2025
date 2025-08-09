module;

#include <SFML/Graphics.hpp>


export module gl.render;

import modules.scheduler.accessors.ecs.Query;
import modules.scheduler.accessors.resources.Resource;
import modules.scheduler.accessors.states.State;
import components.Drawable;
import components.Position;
import window.Window;
import states.GlobalState;
import states.Shaders;
import states.Textures;
import gl.VertexBufs;

using namespace modules::scheduler::accessors;
using namespace window;

namespace gl {

export auto init_draw(const Resource<VertexBuffers>& vertex_buffers) -> void;

export auto draw_world(
    Query<Position, Drawable>&     drawable_query,
    Resource<Window>               window,
    State<GlobalState>             global_state,
    State<Shaders>                 shaders,
    State<Textures>                textures,
    const Resource<VertexBuffers>& vertexBufs
) -> void;

export sf::Glsl::Mat4 calculate_MVP(const Window& window, const GlobalState& global_state);

}   // namespace gl

export auto initialize() -> void;
