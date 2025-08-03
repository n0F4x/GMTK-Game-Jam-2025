module logic.event_handlers.handle_game_pause_event;

import extensions.scheduler.accessors;

import events.GamePauseEvent;
import common.AnimationTimer;
import states.GamePausedState;

using namespace extensions::scheduler::accessors;

auto handle_game_pause_event(
    const Reader<GamePauseEvent>       reader,
    const State<GamePausedState>       game_paused_state,
    const Resource<GameTimer>          game_timer,
    const Receiver<CurrentTimeMessage> current_time
) -> void
{
    if (!reader.read().empty()) {
        const bool paused = reader.read().back().type == GamePause::ePause;

        if (paused) {
            game_paused_state.emplace();
        }
        else {
            game_paused_state.reset();
            game_timer->reset(current_time.receive().front().value);
        }
    }
}
