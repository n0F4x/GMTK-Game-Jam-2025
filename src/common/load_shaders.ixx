//
// Copied by kosmx on 2025-07-31.
//

module;

export module common.load_shaders;

import states.Shaders;
import common.ShaderLoader;
import ddge.modules.execution;

using namespace ddge::exec::accessors;

using CachedShaderLoader = Cached<ShaderLoader>;

export auto load_shaders(
    const State<Shaders>     shadersState,
    const CachedShaderLoader shader_loader
) -> void
{
    if (!shadersState.has_value()) {
        shadersState.emplace(Shaders{ .generic_draw = shader_loader->load("generic") });
    }
}
