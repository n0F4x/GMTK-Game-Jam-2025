module create_shut_down_task_builder;

import extensions.scheduler;

import window.close_window;

auto create_shut_down_task_builder() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::start_as(window::close_window);
}
