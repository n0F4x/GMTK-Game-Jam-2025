module;

#include <utility>

module setup;

import app;

import core.time.Timer;

import plugins.assets;
import plugins.events;
import plugins.functional;
import plugins.messages;
import plugins.resources;
import plugins.states;

import AppBuilder;

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

auto setup(AppBuilder&& builder) -> AppBuilder   //
{
    static_assert(app::has_plugins_c<AppBuilder, plugins::Assets>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::Events>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::Functional>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::Messages>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::Resources>);
    static_assert(app::has_plugins_c<AppBuilder, plugins::States>);

    return std::move(builder)
        .transform(window::setup)
        .insert_resource(core::time::Timer{})
        .insert_resource(AnimationTimer{})
        .insert_resource(GameTimer{})
        .insert_resource(window::DisplayTimer{})
        .insert_resource(SpawnerTimer{})
        .register_event<GamePauseEvent>()
        .register_event<SpawnDialogEvent>()
        .register_state<DialogState>()
        .register_state<GamePausedState>()
        .register_state<GlobalState>()
        .register_state<Textures>()
        .register_state<Shaders>()
        .register_state<Fonts>()
        .register_message<CurrentTimeMessage>()
        .insert_loader(SoundBufferLoader{})
        .insert_loader(TextureLoader{})
        .insert_loader(ShaderLoader{})
        .insert_loader(LevelLoader{})
        .insert_loader(FontLoader{});
}
