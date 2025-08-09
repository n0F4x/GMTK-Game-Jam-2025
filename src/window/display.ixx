export module window.display;

import modules.scheduler.accessors.resources;

import window.Window;

using namespace modules::scheduler::accessors;

namespace window {

export auto display(Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::display(const resources::Resource<Window> window) -> void
{
    window->display();
}
