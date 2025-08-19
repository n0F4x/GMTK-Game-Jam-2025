module create_app_is_running_task_builder;

import ddge.modules.execution;

import ddge.utility.not_fn;

import window.window_should_close;

auto create_app_is_running_task_builder() -> ddge::exec::TaskBuilder<bool>
{
    return ddge::exec::all_of(ddge::util::not_fn(window::window_should_close));
}
