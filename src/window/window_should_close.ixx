module;

#include <print>
#include <span>

export module window.window_should_close;

import modules.scheduler.accessors.events.Reader;

import events.WindowEvent;

using namespace modules::scheduler::accessors;

namespace window {

export auto window_should_close(const Reader<WindowEvent>& closed_event_reader)
    -> bool;

}   // namespace window

module :private;

auto window::window_should_close(const Reader<WindowEvent>& closed_event_reader)
    -> bool
{
    for (const WindowEvent& event : closed_event_reader.read()) {
        if (event.is<WindowEvent::Closed>()) {
            return true;
        }
    }
    return false;
}
