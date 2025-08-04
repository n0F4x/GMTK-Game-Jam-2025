module;

#include <thread>

module create_loop_game_task_builder;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import common.GlobalTimer;
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

auto sleep_until_next_iteration(const Resource<GlobalTimer> global_timer) -> void
{
    const auto now{ GlobalTimer::Clock::now() };
    const auto frame_duration{ global_timer->tick_duration() };
    const auto elapsed_frame_time{ now - global_timer->current() };

    std::this_thread::sleep_for(frame_duration - elapsed_frame_time);

    global_timer->reset();
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
            .then(create_render_task_builder())
            .then(sleep_until_next_iteration),
        create_app_is_running_task_builder()
    );
}
