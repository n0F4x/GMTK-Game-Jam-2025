export module loop_game;

import core.scheduler;
import extensions.scheduler.accessors;

import render;
import should_exit;
import update;
import window.resize;

using namespace extensions::scheduler::accessors;

auto process_events(const events::Processor& event_processor) -> void;

auto clear_messages(const messages::Mailbox& mailbox) -> void;

export inline constexpr auto loop_game = core::scheduler::loop_until(
    core::scheduler::start_as(
        core::scheduler::group(
            process_events,   //
            clear_messages
        )
    )
        .then(window::resize_window)
        .then(update)
        .then(render),
    app_is_running
);

module :private;

auto process_events(const events::Processor& event_processor) -> void
{
    event_processor.process_events();
}

auto clear_messages(const messages::Mailbox& mailbox) -> void
{
    mailbox.clear_messages();
}
