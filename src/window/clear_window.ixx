module;

#include <SFML/Graphics.hpp>

#include <GL/gl.h>

export module window.clear_window;

import extensions.scheduler.accessors.resources;

import window.Window;

using namespace extensions::scheduler::accessors;

namespace window {

export auto clear_window(resources::Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::clear_window(const resources::Resource<Window> window) -> void
{
    glClearColor(100/256.f, 100/256.f, 100/256.f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}
