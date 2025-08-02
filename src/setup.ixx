module;

#include <utility>

export module setup;

import app;

import plugins.assets;
import plugins.functional;
import plugins.states;

import common.AnimationTimer;
import common.GlobalState;
import common.SoundBufferLoader;
import common.TextureLoader;
import common.ShaderLoader;
import common.FontLoader;
import common.Fonts;
import common.Textures;
import common.Shaders;
import window.DisplayTimer;

import window.setup;

export inline constexpr auto setup =
    []<app::decays_to_builder_c Builder_T>(Builder_T&& builder) {
        static_assert(app::has_plugins_c<Builder_T, plugins::AssetsTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::Functional>);
        static_assert(app::has_plugins_c<Builder_T, plugins::StatesTag>);

        return std::forward<Builder_T>(builder)
            .transform(window::setup)
            .insert_resource(AnimationTimer{})
            .insert_resource(window::DisplayTimer{})
            .template register_state<GlobalState>()
            .template register_state<Textures>()
            .template register_state<Shaders>()
            .template register_state<Fonts>()
            .insert_loader(SoundBufferLoader{})
            .insert_loader(TextureLoader{})
            .insert_loader(ShaderLoader{})
            .insert_loader(FontLoader{});
    };
