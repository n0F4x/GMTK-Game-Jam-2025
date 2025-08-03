module initialize;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

import common.load_textures;
import common.load_shaders;
import common.load_fonts;
import common.LevelLoader;
import player.create_player;
import level.create_tiles;
import gl.initialize;
import ui.initialize;
import reset_timers;
import level.draw_level;
import level.place_home;

const core::scheduler::TaskBuilder<void> initialize =
    extensions::scheduler::start_as(gl::initialize)   //
        .then(load_textures)
        .then(load_shaders)
        .then(load_fonts)
        .then(load_levels)
        .then(create_tiles)
        .then(draw_level)
        .then(ui::initialize)
        .then(create_player)
        .then(place_home)
        .then(reset_timers);
