module create_app_is_running_task_builder;

import modules.scheduler;

import utility.not_fn;

import window.window_should_close;

auto create_app_is_running_task_builder() -> modules::scheduler::TaskBuilder<bool>
{
    return modules::scheduler::all_of(util::not_fn(window::window_should_close));
}
