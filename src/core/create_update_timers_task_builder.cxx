module;

#include <cassert>
#include <chrono>

module create_update_timers_task_builder;

import core.time.FixedTimer;
import core.scheduler.TaskBuilder;

import extensions.scheduler;

import common.AnimationTimer;
import common.GameTimer;
import messages.CurrentTimeMessage;
import states.GamePausedState;
import spawner.SpawnerTimer;
import window.DisplayTimer;

using namespace extensions::scheduler::accessors;

auto update_timers(
    const Resource<AnimationTimer>       animation_timer,
    const Resource<GameTimer>            game_timer,
    const Resource<window::DisplayTimer> display_timer,
    const Resource<SpawnerTimer>         spawner_timer,
    const Receiver<CurrentTimeMessage>   current_time_messages,
    const State<GamePausedState>         game_paused_state
) -> void
{
    assert(current_time_messages.receive().size() == 1);

    const auto now = current_time_messages.receive().front().value;

    if (!game_paused_state.has_value()) {
        game_timer->update(now);
    }

    animation_timer->update(now);
    display_timer->update(now);
    spawner_timer->update(now);
}

auto create_update_timers_task_builder() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::start_as(update_timers);
}
