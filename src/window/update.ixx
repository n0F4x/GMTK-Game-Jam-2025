module;

#include <utility>

#include <SFML/Window.hpp>

export module window.update;

import core.scheduler;
import core.time.FixedTimer;

import extensions.scheduler.accessors.events.Recorder;
import extensions.scheduler.accessors.resources;

import window.DisplayTimer;
import window.Window;

import events.WindowEvent;

using namespace extensions::scheduler::accessors;

namespace window {

export auto update(
    resources::Resource<Window>          window,
    const events::Recorder<WindowEvent>& event_recorder,
    resources::Resource<DisplayTimer>    display_timer
) -> void;

}   // namespace window

module :private;

auto window::update(
    const resources::Resource<Window>       window,
    const events::Recorder<WindowEvent>&    event_recorder,
    const resources::Resource<DisplayTimer> display_timer
) -> void
{
    window->handleEvents([&event_recorder]<typename Event>(Event&& event) -> void {
        event_recorder.record(std::forward<Event>(event));
    });

    display_timer->update();
}
