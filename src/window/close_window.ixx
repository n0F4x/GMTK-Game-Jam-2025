export module window.close_window;

import extensions.scheduler.accessors.resources;

import window.Window;

using namespace extensions::scheduler::accessors;

namespace window {

export auto close_window(resources::Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::close_window(const resources::Resource<Window> window) -> void
{
    return window->close();
}
