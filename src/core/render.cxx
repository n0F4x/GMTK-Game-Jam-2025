module render;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import window.DisplayTimer;
import window.clear_window;
import window.display;
import gl.render;
import gl.render_extra;

const core::scheduler::TaskBuilder<void> render =                 //
    extensions::scheduler::at_fixed_rate<window::DisplayTimer>(   //
        extensions::scheduler::start_as(window::clear_window)     //
                                                                  //.then(draw)
            .then(gl::init_draw)
            .then(gl::draw_world)
            .then(gl::render_extra)
            .then(window::display)
    );
