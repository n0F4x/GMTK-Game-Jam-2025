module;

#include <SFML/Graphics.hpp>

export module player.create_player;

import player.Player;
import weapon.Weapon;
import extensions.scheduler;
import common.GlobalState;
import common.Position;
import common.Textures;
import common.Drawable;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

export auto create_player(
    Registry            registry,
    State<GlobalState>  globalState
) -> void;

module :private;

auto create_player(
    const Registry            registry,
    const State<GlobalState>  globalState
) -> void
{
    const auto id = registry->create(Player{}, Position{sf::Vector2f{ 0, 0 }},
        Drawable{Texture::PlayerIdle[0]}, Weapon{});
    globalState.emplace(GlobalState{ .player_id = id });
}
