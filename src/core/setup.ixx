module;

#include <utility>

export module setup;

import app;

import core.time.Timer;

import plugins.assets;
import plugins.events;
import plugins.functional;
import plugins.messages;
import plugins.resources;
import plugins.states;

import common.AnimationTimer;
import common.GameTimer;
import common.SoundBufferLoader;
import common.TextureLoader;
import common.ShaderLoader;
import common.FontLoader;
import common.LevelLoader;

import events.GamePauseEvent;
import events.SpawnDialogEvent;

import messages.CurrentTimeMessage;

import states.DialogState;
import states.GamePausedState;
import states.GlobalState;
import states.Fonts;
import states.Textures;
import states.Shaders;

import spawner.SpawnerTimer;

import window.DisplayTimer;
import window.setup;

export inline constexpr auto setup =
    []<app::decays_to_builder_c Builder_T>(Builder_T&& builder) {
        static_assert(app::has_plugins_c<Builder_T, plugins::AssetsTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::EventsTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::Functional>);
        static_assert(app::has_plugins_c<Builder_T, plugins::MessagesTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::ResourcesTag>);
        static_assert(app::has_plugins_c<Builder_T, plugins::StatesTag>);

        return std::forward<Builder_T>(builder)
            .transform(window::setup)
            .insert_resource(core::time::Timer{})
            .insert_resource(AnimationTimer{})
            .insert_resource(GameTimer{})
            .insert_resource(window::DisplayTimer{})
            .insert_resource(SpawnerTimer{})
            .template register_event<GamePauseEvent>()
            .template register_event<SpawnDialogEvent>()
            .template register_state<DialogState>()
            .template register_state<GamePausedState>()
            .template register_state<GlobalState>()
            .template register_state<Textures>()
            .template register_state<Shaders>()
            .template register_state<Fonts>()
            .template register_message<CurrentTimeMessage>()
            .insert_loader(SoundBufferLoader{})
            .insert_loader(TextureLoader{})
            .insert_loader(ShaderLoader{})
            .insert_loader(LevelLoader{})
            .insert_loader(FontLoader{});
    };
