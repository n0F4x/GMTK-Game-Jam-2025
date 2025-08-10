module;

#include <iostream>

#include <SFML/Graphics.hpp>

#include <GL/gl.h>

export module window.clear_window;

import ddge.modules.scheduler.accessors.resources;

import window.Window;

using namespace ddge::scheduler::accessors;

namespace window {

export auto clear_window(Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::clear_window(const resources::Resource<Window> window) -> void
{
    if (!window->setActive(true)) {
        std::cerr << "Failed to set game window as active OpenGL context" << std::endl;
    }
    glClearColor(100 / 256.f, 100 / 256.f, 100 / 256.f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (!window->setActive(false)) {
        std::cerr << "Failed to unset OpenGL context" << std::endl;
    }
}
