module;

#include <string>
#include <utility>

#include <SFML/Window.hpp>

module window.setup;

import app.decays_to_builder_c;
import app.has_plugins_c;

import core.time.FixedTimer;

import plugins.events;
import plugins.resources;

import AppBuilder;

import events.WindowEvent;

import window.Window;
import gl.VertexBufs;

auto window::setup(AppBuilder&& builder) -> AppBuilder   //
{
    static_assert(app::has_plugins_c<AppBuilder, plugins::Resources>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::Events>);

    constexpr sf::ContextSettings settings{ .depthBits    = 24,
                                            .majorVersion = 4,
                                            .minorVersion = 6,
#ifndef NDEBUG
                                            .attributeFlags = sf::ContextSettings::Debug
#endif
    };

    return std::move(builder)
        .insert_resource(
            Window{ sf::VideoMode::getDesktopMode(), "Fred's Hell", {}, settings }
        )
        .insert_resource(gl::VertexBuffers{})
        .register_event<WindowEvent>();
}
