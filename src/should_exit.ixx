export module should_exit;

import core.scheduler;

import utility.not_fn;

import window.window_should_close;

export inline constexpr auto app_is_running =
    core::scheduler::all_of(util::not_fn(window::window_should_close));
