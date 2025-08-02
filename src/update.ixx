export module update;

import core.scheduler;

import common.AnimationTimer;
import common.GameTimer;

import logic.progress_animations;
import player.update_player;
import enemy.update_enemy;
import window.update;
import weapon.fire_weapon;
import weapon.move_projectiles;
import update_timers;
import physics.physics;

export inline constexpr auto update =           //
    core::scheduler::start_as(window::update)   //
        .then(fire_weapon)
        .then(core::scheduler::at_fixed_rate<GameTimer>(move_projectiles))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_enemy))
        .then(core::scheduler::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(core::scheduler::at_fixed_rate<GameTimer>(physics::move_moveables));
