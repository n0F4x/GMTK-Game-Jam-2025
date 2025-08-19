module create_render_task_builder;

import ddge.modules.execution;

import window.DisplayTimer;
import window.clear_window;
import window.display;
import gl.render;
import gl.render_extra;

auto create_render_task_builder() -> ddge::exec::TaskBuilder<void>
{
    return ddge::exec::at_fixed_rate<window::DisplayTimer>(   //
        ddge::exec::start_as(window::clear_window)            //
                                                                         //.then(draw)
            .then(gl::init_draw)
            .then(gl::draw_world)
            .then(gl::render_extra)
            .then(window::display)
    );
}
