export module render;

import core.scheduler;

import window.DisplayTimer;
import window.clear_window;
import window.display;
import draw;

export inline constexpr auto render =                       //
    core::scheduler::at_fixed_rate<window::DisplayTimer>(   //
        core::scheduler::start_as(window::clear_window)     //
            .then(draw)
            .then(window::display)
    );
