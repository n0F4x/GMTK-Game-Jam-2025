export module initialize;

import core.scheduler;

import common.load_textures;
import common.load_shaders;
import common.load_fonts;
import player.create_player;
import enemy.create_enemies;
import gl.initialize;
import ui.initUI;
import reset_timers;

export inline constexpr auto initialize =
    core::scheduler::start_as(gl::initialize)   //
        .then(load_textures)
        .then(load_shaders)
        .then(load_fonts)
        .then(ui::createUI)
        .then(create_player)
        .then(create_enemies)
        .then(reset_timers);
