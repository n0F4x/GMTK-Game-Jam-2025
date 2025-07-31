module;

#include <utility>
#include <memory>

#include <SFML/Graphics.hpp>

export module setup;

import app;

import plugins.assets;
import plugins.functional;
import plugins.states;

import common.GlobalState;
import common.SoundBufferLoader;
import common.TextureLoader;

import window.setup;

export inline constexpr auto setup =
    []<app::decays_to_builder_c Builder_T>(Builder_T&& builder) {
        static_assert(app::has_plugins_c<Builder_T, plugins::AssetsTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::Functional>);
        static_assert(app::has_plugins_c<Builder_T, plugins::StatesTag>);

        return std::forward<Builder_T>(builder)
            .transform(window::setup)
            .template register_state<GlobalState>()
            .insert_loader(SoundBufferLoader{})
            .insert_loader(TextureLoader{});
    };
