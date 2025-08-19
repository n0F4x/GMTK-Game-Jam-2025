module;

#include <chrono>
#include <format>

export module window.display_fps;

import ddge.modules.execution.accessors.resources;

import ddge.modules.time.Timer;

import window.Window;

using namespace std::chrono_literals;
using namespace ddge::exec::accessors;

namespace window {

export auto display_fps(Resource<ddge::time::Timer> global_timer, Resource<Window> window)
    -> void;

}   // namespace window

module :private;

auto window::display_fps(
    const Resource<ddge::time::Timer> global_timer,
    const Resource<Window>            window
) -> void
{
    window->setTitle(std::format("FPS: {}", 1s / global_timer->delta()));
}
