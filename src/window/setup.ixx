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

import window.DisplayTimer;
import window.Window;
import gl.VertexBufs;

namespace window {

export inline constexpr auto setup =
    []<app::decays_to_builder_c Builder_T>(Builder_T&& builder) {
        static_assert(app::has_plugins_c<Builder_T, plugins::ResourcesTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::EventsTag>);

        return std::forward<Builder_T>(builder)
            .insert_resource(
                Window{ sf::VideoMode::getDesktopMode(), "Title" }
            )   // TODO window.setVerticalSyncEnabled(true);
            .insert_resource(DisplayTimer{})
            .insert_resource(gl::VertexBufs{})
            .template register_event<WindowEvent>();
    };

}   // namespace window
