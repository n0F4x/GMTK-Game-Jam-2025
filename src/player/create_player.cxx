module;

#include <SFML/Graphics.hpp>

module player.create_player;

import extensions.scheduler;

import states.GlobalState;
import states.Textures;

import components.Drawable;
import components.Health;
import components.Hitbox;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Velocity;
import components.Weapon;
import components.AttackAttributes;

import player.idle_animation;

using namespace extensions::scheduler::accessors;

auto create_player(const Registry registry, const State<GlobalState> globalState) -> void
{
    const auto id = registry->create(
        Player{
    },
        Position{ sf::Vector2f{ 0, 0 } },
        Drawable{ textures::player_idle[0] },
        Health{ 100 },
        MovementSpeed{ 0.1f },
        Weapon{},
        AttackAttributes{},
        Hitbox{},
        Velocity{},
        idle_animation()
    );

    if (!globalState.has_value()) {
        globalState.emplace(GlobalState{ .player_id = id });
    }
    else {
        globalState->player_id = id;
    }
}
