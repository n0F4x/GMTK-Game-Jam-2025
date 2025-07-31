export module update;

import core.scheduler;

import window.update;

export inline constexpr auto update = core::scheduler::start_as(window::update);
