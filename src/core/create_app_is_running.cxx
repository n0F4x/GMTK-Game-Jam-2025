module create_app_is_running;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import utility.not_fn;

import window.window_should_close;

auto create_app_is_running() -> core::scheduler::TaskBuilder<bool>
{
    return extensions::scheduler::all_of(util::not_fn(window::window_should_close));
}
