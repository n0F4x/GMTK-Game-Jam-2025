export module update;

import core.scheduler;

import common.AnimationTimer;
import common.GameTimer;
import spawner.SpawnerTimer;

import logic.progress_animations;
import logic.pause_or_resume_game_on_input;
import player.update_player;
import enemy.update_enemy;
import spawner.update_spawner;
import window.update;
import weapon.fire_weapon;
import weapon.move_projectiles;
import player.follow_player;
import update_timers;
import physics.physics;

export inline constexpr auto update =           //
    core::scheduler::start_as(window::update)   //
        .then(pause_or_resume_game_on_input)
        .then(weapon::fire_player_weapon)
        .then(core::scheduler::at_fixed_rate<GameTimer>(weapon::update_projectiles))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(core::scheduler::at_fixed_rate<GameTimer>(update_enemy))
        .then(core::scheduler::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(core::scheduler::at_fixed_rate<GameTimer>(physics::move_moveables))
        .then(core::scheduler::at_fixed_rate<GameTimer>(follow_player))
        .then(core::scheduler::at_fixed_rate<SpawnerTimer>(update_spawner));
