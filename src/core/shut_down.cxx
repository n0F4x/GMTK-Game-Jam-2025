module shut_down;

import extensions.scheduler;

import window.close_window;

const core::scheduler::TaskBuilder<void> shut_down = extensions::scheduler::start_as(window::close_window);
