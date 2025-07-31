export module shutdown;

import core.scheduler;

import window.close_window;

export constexpr inline auto shut_down = core::scheduler::start_as(window::close_window);
