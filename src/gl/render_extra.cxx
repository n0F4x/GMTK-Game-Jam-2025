module;


#include <cassert>
#include <iostream>

#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <GL/glew.h>


module gl.render_extra;

import extensions.scheduler.accessors.ecs.Query;
import extensions.scheduler.accessors.resources.Resource;
import extensions.scheduler.accessors.states.State;
import extensions.scheduler;
import window.Window;
import common.GlobalState;
import common.Shaders;
import common.Textures;
import gl.VertexBufs;
import components.SFMLComponent;


using namespace extensions::scheduler::accessors;
using namespace window;

auto gl::render_extra(const Registry registry, const Resource<Window> window) -> void
{
    if (window->setActive(true)) {
        glBindVertexArray(0);
        glDisable(GL_DEPTH_TEST);
        window->pushGLStates();

        core::ecs::query(registry.get(), [&window](SFMLComponent& component) {
            component.component->draw(window.get());
        });

        window->popGLStates();
        glEnable(GL_DEPTH_TEST);
        if (!window->setActive(false)) {
            std::cerr << "Failed to release window" << std::endl;
        }
    }
}
