export module initialize;

import core.scheduler;
import window.initialize;
import common.load_textures;
import common.load_shaders;
import player.create_player;
import enemy.create_enemy;
import gl.initialize;

export inline constexpr auto initialize =
    core::scheduler::start_as(window::initialize)   //
        .then(gl::initialize)
        .then(load_textures)
        .then(load_shaders)
        .then(create_player)
        .then(create_enemy);
