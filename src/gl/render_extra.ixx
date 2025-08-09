module;

#include <SFML/Graphics.hpp>


export module gl.render_extra;

import modules.scheduler;

import window.Window;
import states.GlobalState;
import states.Shaders;
import states.Textures;
import gl.VertexBufs;
import modules.ecs;

using namespace modules::scheduler::accessors;
using namespace window;

namespace gl {

export auto render_extra(Registry registry, Resource<Window> window) -> void;

}   // namespace gl
