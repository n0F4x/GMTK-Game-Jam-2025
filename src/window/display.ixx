export module window.display;

import ddge.modules.execution.accessors.resources;

import window.Window;

using namespace ddge::exec::accessors;

namespace window {

export auto display(Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::display(const resources::Resource<Window> window) -> void
{
    window->display();
}
