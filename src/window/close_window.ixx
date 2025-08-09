export module window.close_window;

import modules.scheduler.accessors.resources;

import window.Window;

using namespace modules::scheduler::accessors;

namespace window {

export auto close_window(Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::close_window(const resources::Resource<Window> window) -> void
{
    return window->close();
}
