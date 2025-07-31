module;

#include <SFML/Graphics.hpp>

export module window.clear_window;

import extensions.scheduler.accessors.resources;

import window.Window;

using namespace extensions::scheduler::accessors;

namespace window {

export auto clear_window(resources::Resource<Window> window) -> void;

}   // namespace window

module :private;

auto window::clear_window(const resources::Resource<Window> window) -> void
{
    window->clear(sf::Color{ 100, 100, 100 });
}
