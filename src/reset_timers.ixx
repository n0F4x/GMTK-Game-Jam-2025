module;

#include <chrono>

export module reset_timers;

import core.time.FixedTimer;

import extensions.scheduler.accessors.resources;

import common.AnimationTimer;
import common.GameTimer;
import spawner.SpawnerTimer;
import window.DisplayTimer;

using namespace extensions::scheduler::accessors;

export auto reset_timers(
    Resource<AnimationTimer>       animation_timer,
    Resource<GameTimer>            game_timer,
    Resource<window::DisplayTimer> display_timer,
    Resource<SpawnerTimer>         spawner_timer
) -> void;

module :private;

auto reset_timers(
    const Resource<AnimationTimer>       animation_timer,
    const Resource<GameTimer>            game_timer,
    const Resource<window::DisplayTimer> display_timer,
    const Resource<SpawnerTimer>         spawner_timer
) -> void
{
    const auto now = std::chrono::steady_clock::now();

    animation_timer->reset(now);
    game_timer->reset(now);
    display_timer->reset(now);
    spawner_timer->reset(now);
}
