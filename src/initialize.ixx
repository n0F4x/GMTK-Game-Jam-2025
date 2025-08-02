export module initialize;

import core.scheduler;
import window.initialize;
import common.load_textures;
import common.load_shaders;
import player.create_player;
import enemy.create_enemies;
import gl.initialize;
import ui.initUI;

export inline constexpr auto initialize =
    core::scheduler::start_as(window::initialize)   //
        .then(gl::initialize)
        .then(load_textures)
        .then(load_shaders)
        .then(ui::createUI)
        .then(create_player)
        .then(create_enemies);
