module create_shut_down_task_builder;

import ddge.modules.execution;

import window.close_window;

auto create_shut_down_task_builder() -> ddge::exec::TaskBuilder<void>
{
    return ddge::exec::start_as(window::close_window);
}
