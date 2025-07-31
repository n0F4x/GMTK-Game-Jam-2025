export module initialize;

import core.scheduler;

import window.initialize;

export inline constexpr auto initialize = core::scheduler::start_as(window::initialize);
