export module common.load_textures;

import common.Textures;
import common.TextureLoader;
import extensions.scheduler;

using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedTextureLoader =
    extensions::scheduler::accessors::assets::Cached<TextureLoader>;

export auto load_textures(
    State<Textures>     texturesState,   //
    CachedTextureLoader texture_loader
) -> void;

module :private;

auto load_textures(
    const State<Textures>     texturesState,
    const CachedTextureLoader texture_loader
) -> void
{
    if (!texturesState.has_value()) {
        texturesState.emplace(texture_loader->load("atlas.png"));
    }
}
