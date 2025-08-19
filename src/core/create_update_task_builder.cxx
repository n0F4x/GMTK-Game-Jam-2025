module create_update_task_builder;

import ddge.modules.execution;

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

auto create_update_task_builder() -> ddge::exec::TaskBuilder<void>
{
    return ddge::exec::start_as(window::update)   //
        .then(window::display_fps)
        .then(update_dialogs)
        .then(weapon::fire_player_weapon)
        .then(ddge::exec::at_fixed_rate<GameTimer>(weapon::update_projectiles))
        .then(ddge::exec::at_fixed_rate<GameTimer>(update_player))
        .then(ddge::exec::at_fixed_rate<GameTimer>(update_enemy))
        .then(ddge::exec::at_fixed_rate<AnimationTimer>(progress_animations))
        .then(ddge::exec::at_fixed_rate<GameTimer>(physics::move_moveables))
        .then(ddge::exec::at_fixed_rate<GameTimer>(follow_player))
        .then(ddge::exec::at_fixed_rate<GameTimer>(destroy_dead_enemies))
        .then(ddge::exec::at_fixed_rate<SpawnerTimer>(update_spawner));
}
