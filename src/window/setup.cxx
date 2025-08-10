module;

#include <string>
#include <utility>

#include <SFML/Window.hpp>

module window.setup;

import ddge.prelude;
import ddge.modules.time.FixedTimer;

import AppBuilder;

import events.WindowEvent;

import window.Window;
import gl.VertexBufs;

auto window::setup(AppBuilder&& builder) -> AppBuilder   //
{
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Resources>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Events>);

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
