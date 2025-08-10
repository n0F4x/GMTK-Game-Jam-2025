module create_shut_down_task_builder;

import ddge.modules.scheduler;

import window.close_window;

auto create_shut_down_task_builder() -> ddge::scheduler::TaskBuilder<void>
{
    return ddge::scheduler::start_as(window::close_window);
}
