module create_shut_down_task_builder;

import modules.scheduler;

import window.close_window;

auto create_shut_down_task_builder() -> modules::scheduler::TaskBuilder<void>
{
    return modules::scheduler::start_as(window::close_window);
}
