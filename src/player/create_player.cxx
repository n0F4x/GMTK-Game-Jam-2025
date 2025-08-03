module;

#include <SFML/Graphics.hpp>

module player.create_player;

import extensions.scheduler;

import common.textures;

import components.Drawable;
import components.Health;
import components.Hitbox;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Velocity;
import components.Weapon;
import components.AttackAttributes;

import events.SpawnDialogEvent;

import states.GlobalState;

import player.animations;

using namespace extensions::scheduler::accessors;

auto create_player(
    const Registry             registry,
    const State<GlobalState>   globalState,
    Recorder<SpawnDialogEvent> dialog_recorder
) -> void
{
    const auto id = registry->create(
        Player{
    },
        Position{ sf::Vector2f{ 2, -3 } },
        Drawable{ textures::player_idle[0] },
        Health{ 100 },
        MovementSpeed{ 6.f },
        Weapon{},
        AttackAttributes{},
        Hitbox{},
        Velocity{},
        idle_animation_front(true)
    );

    if (!globalState.has_value()) {
        globalState.emplace(GlobalState{ .player_id = id });
    }
    else {
        globalState->player_id = id;
    }

    dialog_recorder.record(
        SpawnDialogEvent{
            .text  = "Player has spawned",
            .style = SpawnDialogEvent::Style::eOverworld,
        }
    );
}
