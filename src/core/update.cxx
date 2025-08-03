module update;

import core.scheduler.TaskBuilder;
import extensions.scheduler;

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

const core::scheduler::TaskBuilder<void> update =     //
    extensions::scheduler::start_as(window::update)   //
        .then(update_dialogs)
        .then(weapon::fire_player_weapon)
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(weapon::update_projectiles))
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(update_enemy))
        .then(extensions::scheduler::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(physics::move_moveables))
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(follow_player))
        .then(extensions::scheduler::at_fixed_rate<GameTimer>(destroy_dead_enemies))
        .then(extensions::scheduler::at_fixed_rate<SpawnerTimer>(update_spawner));
