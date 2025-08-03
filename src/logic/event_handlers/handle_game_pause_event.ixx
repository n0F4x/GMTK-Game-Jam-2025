export module logic.event_handlers.handle_game_pause_event;

import extensions.scheduler.accessors;

import common.AnimationTimer;
import events.GamePauseEvent;
import messages.CurrentTimeMessage;
import states.GamePausedState;

using namespace extensions::scheduler::accessors;

export auto handle_game_pause_event(
    Reader<GamePauseEvent>       reader,
    State<GamePausedState>       game_paused_state,
    Resource<AnimationTimer>     animation_timer,
    Receiver<CurrentTimeMessage> current_time
) -> void;
