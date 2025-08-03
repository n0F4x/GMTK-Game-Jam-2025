export module loop_game;

import core.scheduler;
import extensions.scheduler.accessors;

import messages.CurrentTimeMessage;
import logic.handle_events;
import render;
import should_exit;
import update;
import update_timers;

using namespace extensions::scheduler::accessors;

auto send_current_time(const Sender<CurrentTimeMessage>& sender) -> void;

auto process_events(const Processor& event_processor) -> void;

auto clear_messages(const Mailbox& mailbox) -> void;

export inline constexpr auto loop_game = core::scheduler::loop_until(
    core::scheduler::start_as(   //
        core::scheduler::group(
            clear_messages,      //
            process_events
        )
    )
        .then(send_current_time)
        .then(
            core::scheduler::group(
                handle_events,   //
                update_timers
            )
        )
        .then(update)
        .then(render),
    app_is_running
);

module :private;

auto send_current_time(const Sender<CurrentTimeMessage>& sender) -> void
{
    sender.send();
}

auto process_events(const Processor& event_processor) -> void
{
    event_processor.process_events();
}

auto clear_messages(const Mailbox& mailbox) -> void
{
    mailbox.clear_messages();
}
