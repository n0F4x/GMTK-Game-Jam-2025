module;

#include <SFML/Graphics.hpp>


export module gl.render_extra;

import extensions.scheduler.accessors.ecs.Query;
import extensions.scheduler.accessors.resources.Resource;
import extensions.scheduler.accessors.states.State;
import extensions.scheduler;
import window.Window;
import common.GlobalState;
import common.Shaders;
import common.Textures;
import gl.VertexBufs;
import core.ecs;

using namespace extensions::scheduler::accessors;
using namespace window;

namespace gl {

export auto render_extra(Registry registry, Resource<Window> window) -> void;

}   // namespace gl
