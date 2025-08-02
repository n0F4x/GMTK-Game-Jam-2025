module;

#include <chrono>

export module update_timers;

import core.time.FixedTimer;

import extensions.scheduler.accessors.resources;

import common.AnimationTimer;
import common.GameTimer;
import window.DisplayTimer;

using namespace extensions::scheduler::accessors;

export auto update_timers(
    Resource<AnimationTimer>       animation_timer,
    Resource<window::DisplayTimer> display_timer
) -> void;

module :private;

auto update_timers(
    const Resource<AnimationTimer>       animation_timer,
    const Resource<window::DisplayTimer> display_timer
) -> void
{
    const auto now = std::chrono::steady_clock::now();

    animation_timer->update(now);
    display_timer->update(now);
}
