module;

#include <utility>

module setup;

import ddge.prelude;
import ddge.modules.time.Timer;

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
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Assets>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Events>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Functional>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Messages>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::Resources>);
    static_assert(ddge::app::has_plugins_c<AppBuilder, ddge::plugins::States>);

    return std::move(builder)
        .transform(window::setup)
        .insert_resource(ddge::time::Timer{})
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
