module create_render_task_builder;

import ddge.modules.scheduler;

import window.DisplayTimer;
import window.clear_window;
import window.display;
import gl.render;
import gl.render_extra;

auto create_render_task_builder() -> ddge::scheduler::TaskBuilder<void>
{
    return ddge::scheduler::at_fixed_rate<window::DisplayTimer>(   //
        ddge::scheduler::start_as(window::clear_window)            //
                                                                         //.then(draw)
            .then(gl::init_draw)
            .then(gl::draw_world)
            .then(gl::render_extra)
            .then(window::display)
    );
}
