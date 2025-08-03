module loop_game;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import messages.CurrentTimeMessage;
import logic.handle_events;

import app_is_running;
import render;
import update;
import update_timers;

using namespace extensions::scheduler::accessors;

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

const core::scheduler::TaskBuilder<void> loop_game = extensions::scheduler::loop_until(
    extensions::scheduler::start_as(   //
        extensions::scheduler::group(
            clear_messages,            //
            process_events
        )
    )
        .then(send_current_time)
        .then(
            extensions::scheduler::group(
                handle_events,   //
                update_timers
            )
        )
        .then(update)
        .then(render),
    app_is_running
);
