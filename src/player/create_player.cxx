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

using namespace extensions::scheduler::accessors;

auto create_player(const Registry registry, const State<GlobalState> globalState) -> void
{
    const auto id = registry->create(
        Player{
    },
        Position{ sf::Vector2f{ 0, 0 } },
        Drawable{ texture::PlayerIdle[0] },
        Health{ 100 },
        MovementSpeed{ 0.1f },
        Weapon{}
    );

    globalState.emplace(GlobalState{ .player_id = id });
}
