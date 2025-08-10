module;

#include <chrono>

module create_reset_timers_task_builder;

import ddge.modules.time.Timer;
import ddge.modules.scheduler;

import common.AnimationTimer;
import common.GameTimer;
import spawner.SpawnerTimer;
import window.DisplayTimer;

using namespace ddge::scheduler::accessors;

auto reset_timers(
    const Resource<ddge::time::Timer>    global_timer,
    const Resource<AnimationTimer>       animation_timer,
    const Resource<GameTimer>            game_timer,
    const Resource<window::DisplayTimer> display_timer,
    const Resource<SpawnerTimer>         spawner_timer
) -> void
{
    const auto now = std::chrono::steady_clock::now();

    global_timer->reset(now);
    animation_timer->reset(now);
    game_timer->reset(now);
    display_timer->reset(now);
    spawner_timer->reset(now);
}

auto create_reset_timers_task_builder() -> ddge::scheduler::TaskBuilder<void>
{
    return ddge::scheduler::start_as(reset_timers);
}
