export module initialize;

import core.scheduler;

import common.load_textures;
import common.load_shaders;
import common.load_fonts;
import common.LevelLoader;
import player.create_player;
import enemy.create_enemies;
import level.create_tiles;
import gl.initialize;
import ui.initUI;
import reset_timers;
import level.draw_level;

export inline constexpr auto initialize =
    core::scheduler::start_as(gl::initialize)   //
        .then(load_textures)
        .then(load_shaders)
        .then(load_fonts)
        .then(load_levels)
        .then(create_tiles)
        .then(draw_level)
        .then(ui::createUI)
        .then(create_player)
        .then(create_enemies)
        .then(reset_timers);
