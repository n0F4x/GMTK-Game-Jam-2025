export module render;

import core.scheduler;

import window.DisplayTimer;
import window.clear_window;
import window.resize;
import window.display;
import draw;
import gl.render;

export inline constexpr auto render =                       //
    core::scheduler::at_fixed_rate<window::DisplayTimer>(   //
        core::scheduler::start_as(window::clear_window)     //
                                                          //.then(draw)
            .then(window::resize_window)
            .then(gl::init_draw)
            .then(gl::draw_world)
            .then(window::display)
    );
