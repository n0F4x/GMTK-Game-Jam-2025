module;

#include <memory>

#include <SFML/Graphics.hpp>

export module player.create_player;

import player.Player;
import extensions.scheduler;
import common.GlobalState;
import common.TextureLoader;
import core.assets.Handle;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedTextureLoader =
    extensions::scheduler::accessors::assets::Cached<TextureLoader>;

export auto create_player(
    Registry            registry,
    State<GlobalState>  globalState,
    CachedTextureLoader texture_loader
) -> void;

module :private;

auto create_player(
    const Registry            registry,
    const State<GlobalState>  globalState,
    const CachedTextureLoader texture_loader
) -> void
{
    const core::assets::Handle texture_handle{ texture_loader->load("MC.png") };

    auto player_shape = sf::RectangleShape(sf::Vector2f{ 64, 64 });

    player_shape.setTexture(texture_handle.get());

    const auto id = registry->create(Player{}, sf::Vector2f{ 0, 0 }, player_shape);
    globalState.emplace(GlobalState{ .player_id = id });
}
