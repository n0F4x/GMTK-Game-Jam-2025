export module common.load_textures;

import states.Textures;
import common.TextureLoader;
import ddge.modules.execution;

using namespace ddge::exec::accessors;

using CachedTextureLoader = Cached<TextureLoader>;

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
        texturesState.emplace(
            Textures{
                .atlas            = texture_loader->load("atlas.png"),
                .overworld_dialog = texture_loader->load("Dialog-overworld.png"),
                .hell_dialog      = texture_loader->load("Dialog-hell.png"),
            }
        );
    }
}
