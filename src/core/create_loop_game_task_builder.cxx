module create_loop_game_task_builder;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import messages.CurrentTimeMessage;
import logic.handle_events;

import create_app_is_running_task_builder;
import create_render_task_builder;
import create_update_task_builder;
import create_update_timers_task_builder;

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

auto create_loop_game_task_builder() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::loop_until(
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
                    create_update_timers_task_builder()
                )
            )
            .then(create_update_task_builder())
            .then(create_render_task_builder()),
        create_app_is_running_task_builder()
    );
}
