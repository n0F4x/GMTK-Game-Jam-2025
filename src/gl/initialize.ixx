module;

#include <iostream>

#include <GL/glew.h>

export module gl.initialize;

import extensions.scheduler.accessors.resources.Resource;
import window.Window;
import gl.VertexBufs;

using namespace extensions::scheduler::accessors::resources;
using namespace window;

namespace gl {
export auto initialize(Resource<Window> window, const Resource<VertexBufs>& vertexBufs)
    -> void;
}   // namespace gl

module :private;

auto gl::initialize(const Resource<Window> window, const Resource<VertexBufs>& vertexBufs)
    -> void
{
    if (!window->setActive(true)) {
        std::cerr << "Failed to set window active." << std::endl;
    }
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize glew." << std::endl;
        std::exit(-1);
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);
    glDepthRange(-1.f, 1.f);


    vertexBufs->initialize();
}
