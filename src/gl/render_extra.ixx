module;

#include <SFML/Graphics.hpp>


export module gl.render_extra;

import ddge.modules.execution;

import window.Window;
import states.GlobalState;
import states.Shaders;
import states.Textures;
import gl.VertexBufs;
import ddge.modules.ecs;

using namespace ddge::exec::accessors;
using namespace window;

namespace gl {

export auto render_extra(Registry registry, Resource<Window> window) -> void;

}   // namespace gl
