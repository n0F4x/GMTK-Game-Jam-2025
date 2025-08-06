module;

#include <string>
#include <utility>

#include <SFML/Window.hpp>

export module window.setup;

import app.decays_to_builder_c;
import app.has_plugins_c;

import core.time.FixedTimer;

import plugins.events;
import plugins.resources;

import events.WindowEvent;

import window.Window;
import gl.VertexBufs;

namespace window {

export inline constexpr auto setup =                                           //
    []<app::decays_to_builder_c Builder_T>(Builder_T&& builder) -> Builder_T   //
{
    static_assert(app::has_plugins_c<Builder_T, plugins::Resources>);
    static_assert(app::has_plugins_c<Builder_T, plugins::Events>);

    constexpr sf::ContextSettings settings{ .depthBits    = 24,
                                            .majorVersion = 4,
                                            .minorVersion = 6,
#ifndef NDEBUG
                                            .attributeFlags = sf::ContextSettings::Debug
#endif
    };

    return std::forward<Builder_T>(builder)
        .insert_resource(
            Window{ sf::VideoMode::getDesktopMode(), "Fred's Hell", {}, settings }
        )
        .insert_resource(gl::VertexBuffers{})
        .template register_event<WindowEvent>();
};

}   // namespace window
