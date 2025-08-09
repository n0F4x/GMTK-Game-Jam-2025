module;


#include <cassert>
#include <iostream>

#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <GL/glew.h>


module gl.render_extra;

import modules.scheduler;
import window.Window;
import states.GlobalState;
import states.Shaders;
import states.Textures;
import gl.VertexBufs;
import components.SFMLComponent;


using namespace modules::scheduler::accessors;
using namespace window;

auto gl::render_extra(const Registry registry, const Resource<Window> window) -> void
{
    if (window->setActive(true)) {
        glBindVertexArray(0);
        glDisable(GL_DEPTH_TEST);
        window->pushGLStates();

        modules::ecs::query(registry.get(), [&window](SFMLComponent& component) {
            component.component->draw(window.get());
        });

        window->popGLStates();
        glEnable(GL_DEPTH_TEST);
        if (!window->setActive(false)) {
            std::cerr << "Failed to release window" << std::endl;
        }
    }
}
