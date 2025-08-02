export module update;

import core.scheduler;

import common.GameTimer;
import player.update_player;
import enemy.update_enemy;
import window.update;
import weapon.fire_weapon;
import weapon.move_projectiles;
import update_timers;

export inline constexpr auto update =           //
    core::scheduler::start_as(update_timers)   //
        .then(window::update)
        .then(fire_weapon)
        .then(core::scheduler::at_fixed_rate<GameTimer>(move_projectiles))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_enemy));
