module app_is_running;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import utility.not_fn;

import window.window_should_close;

const core::scheduler::TaskBuilder<bool> app_is_running =
    extensions::scheduler::all_of(util::not_fn(window::window_should_close));
