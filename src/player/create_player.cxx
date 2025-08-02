module;

#include <SFML/Graphics.hpp>

module player.create_player;

import extensions.scheduler;

import common.GlobalState;
import common.Textures;

import components.Drawable;
import components.Health;
import components.MovementSpeed;
import components.Player;
import components.Position;
import components.Weapon;

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
        idle_animation()
    );

    if (!globalState.has_value()) {
        globalState.emplace(GlobalState{ .player_id = id });
    } else {
        globalState->player_id = id;
    }

}
