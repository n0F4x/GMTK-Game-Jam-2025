//
// Copied by kosmx on 2025-07-31.
//

module;

export module common.load_shaders;

import common.Shaders;
import common.ShaderLoader;
import extensions.scheduler;

using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedShaderLoader = extensions::scheduler::accessors::assets::Cached<ShaderLoader>;

export auto load_shaders(
    const State<Shaders>     shadersState,
    const CachedShaderLoader shader_loader
) -> void
{
    if (!shadersState.has_value()) {
        shadersState.emplace(Shaders{ .generic_draw = shader_loader->load("generic") });
    }
}
