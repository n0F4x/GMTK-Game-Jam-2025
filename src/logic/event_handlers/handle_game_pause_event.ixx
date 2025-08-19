export module logic.event_handlers.handle_game_pause_event;

import ddge.modules.execution.accessors;

import common.GameTimer;
import events.GamePauseEvent;
import messages.CurrentTimeMessage;
import states.GamePausedState;

using namespace ddge::exec::accessors;

export auto handle_game_pause_event(
    Reader<GamePauseEvent>       reader,
    State<GamePausedState>       game_paused_state,
    Resource<GameTimer>          game_timer,
    Receiver<CurrentTimeMessage> current_time
) -> void;
