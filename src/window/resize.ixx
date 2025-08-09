module;

#include <iostream>

#include <SFML/Graphics/View.hpp>

#include <GL/gl.h>

export module window.resize;

import modules.scheduler.accessors.resources.Resource;
import events.WindowEvent;
import modules.scheduler.accessors.events.Reader;
import window.Window;


using namespace modules::scheduler::accessors;

namespace window {

export auto resize_window(Reader<WindowEvent> event_reader, Resource<Window> window)
    -> void;

}   // namespace window

module :private;

auto window::resize_window(
    const Reader<WindowEvent> event_reader,
    const Resource<Window>    window
) -> void
{
    for (const WindowEvent& event : event_reader.read()) {
        if (const auto resizeEvent = event.getIf<WindowEvent::Resized>();
            resizeEvent != nullptr)
        {
            if (!window->setActive(true)) {
                std::cerr << "Failed to set window to active" << std::endl;
            }

            // viewport is a 1 side-length square with ...
            // doesn't matter, I'll use MVP anyway
            glViewport(
                0,
                0,
                static_cast<GLsizei>(resizeEvent->size.x),
                static_cast<GLsizei>(resizeEvent->size.y)
            );

            window->setView(
                sf::View{
                    sf::FloatRect{ {}, sf::Vector2f(resizeEvent->size) }
            }
            );

            if (!window->setActive(false)) {
                std::cerr << "Failed release window" << std::endl;
            }
        }
    }
}
