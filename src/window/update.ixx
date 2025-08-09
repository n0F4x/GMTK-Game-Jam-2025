module;

#include <utility>

export module window.update;

import modules.time.FixedTimer;
import modules.scheduler.accessors;

import modules.scheduler.accessors.events.Recorder;
import modules.scheduler.accessors.resources;

import window.Window;

import events.WindowEvent;

using namespace modules::scheduler::accessors;

namespace window {

export auto update(Resource<Window> window, const Recorder<WindowEvent>& event_recorder)
    -> void;

}   // namespace window

module :private;

auto window::update(
    const Resource<Window>       window,
    const Recorder<WindowEvent>& event_recorder
) -> void
{
    window->handleEvents([&event_recorder]<typename Event>(Event&& event) -> void {
        event_recorder.record(std::forward<Event>(event));
    });
}
