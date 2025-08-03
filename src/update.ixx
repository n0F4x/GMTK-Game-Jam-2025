export module update;

import core.scheduler;

import common.AnimationTimer;
import common.GameTimer;
import spawner.SpawnerTimer;

import logic.dialog.update_dialogs;
import logic.progress_animations;

import player.update_player;
import enemy.update_enemy;
import spawner.update_spawner;
import window.update;
import weapon.fire_weapon;
import weapon.move_projectiles;
import player.follow_player;
import update_timers;
import logic.destroy_dead_enemies;
import physics.physics;

export inline constexpr auto update =           //
    core::scheduler::start_as(window::update)   //
        .then(update_dialogs)
        .then(weapon::fire_player_weapon)
        .then(core::scheduler::at_fixed_rate<GameTimer>(weapon::update_projectiles))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_enemy))
        .then(core::scheduler::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(core::scheduler::at_fixed_rate<GameTimer>(physics::move_moveables))
        .then(core::scheduler::at_fixed_rate<GameTimer>(follow_player))
        .then(core::scheduler::at_fixed_rate<GameTimer>(destroy_dead_enemies))
        .then(core::scheduler::at_fixed_rate<SpawnerTimer>(update_spawner));
