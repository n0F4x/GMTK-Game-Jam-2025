module create_update_task_builder;

import modules.scheduler;

import common.AnimationTimer;
import common.GameTimer;
import spawner.SpawnerTimer;

import logic.dialog.update_dialogs;
import logic.progress_animations;

import player.update_player;
import enemy.update_enemy;
import spawner.update_spawner;
import window.update;
import window.display_fps;
import weapon.fire_weapon;
import weapon.move_projectiles;
import player.follow_player;
import logic.destroy_dead_enemies;
import physics.physics;

auto create_update_task_builder() -> modules::scheduler::TaskBuilder<void>
{
    return modules::scheduler::start_as(window::update)   //
        .then(window::display_fps)
        .then(update_dialogs)
        .then(weapon::fire_player_weapon)
        .then(modules::scheduler::at_fixed_rate<GameTimer>(weapon::update_projectiles))
        .then(modules::scheduler::at_fixed_rate<GameTimer>(update_player))
        .then(modules::scheduler::at_fixed_rate<GameTimer>(update_enemy))
        .then(modules::scheduler::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(modules::scheduler::at_fixed_rate<GameTimer>(physics::move_moveables))
        .then(modules::scheduler::at_fixed_rate<GameTimer>(follow_player))
        .then(modules::scheduler::at_fixed_rate<GameTimer>(destroy_dead_enemies))
        .then(modules::scheduler::at_fixed_rate<SpawnerTimer>(update_spawner));
}
