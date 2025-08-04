module create_shut_down;

import extensions.scheduler;

import window.close_window;

auto create_shut_down() -> core::scheduler::TaskBuilder<void>
{
    return extensions::scheduler::start_as(window::close_window);
}
