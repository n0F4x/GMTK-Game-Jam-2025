export module logic.handle_events;

import extensions.scheduler;

import logic.event_handlers.handle_game_pause_event;
import window.resize;

export inline const auto handle_events =
    extensions::scheduler::group(window::resize_window, handle_game_pause_event);
