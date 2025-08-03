export module logic.handle_events;

import core.scheduler;

import logic.event_handlers.handle_game_pause_event;
import window.resize;

export inline constexpr auto handle_events =
    core::scheduler::group(window::resize_window, handle_game_pause_event);
