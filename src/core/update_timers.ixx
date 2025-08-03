export module update_timers;

import core.time.FixedTimer;

import extensions.scheduler.accessors;

import common.AnimationTimer;
import common.GameTimer;
import messages.CurrentTimeMessage;
import states.GamePausedState;
import spawner.SpawnerTimer;
import window.DisplayTimer;

using namespace extensions::scheduler::accessors;

export auto update_timers(
    Resource<AnimationTimer>       animation_timer,
    Resource<GameTimer>            game_timer,
    Resource<window::DisplayTimer> display_timer,
    Resource<SpawnerTimer>         spawner_timer,
    Receiver<CurrentTimeMessage>   current_time_messages,
    State<GamePausedState>         game_paused_state
) -> void;
