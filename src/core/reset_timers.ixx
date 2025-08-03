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
