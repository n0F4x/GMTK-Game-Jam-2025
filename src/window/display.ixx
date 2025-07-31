export module window.display;

import extensions.scheduler.accessors.resources;

import window.Window;

using namespace extensions::scheduler::accessors;

namespace window {

export auto display(resources::Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::display(const resources::Resource<Window> window) -> void
{
    window->display();
}
