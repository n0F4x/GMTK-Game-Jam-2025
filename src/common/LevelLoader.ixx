module;

#include <filesystem>
#include <fstream>

export module common.LevelLoader;

import states.GlobalState;
import ddge.modules.execution;
import ddge.modules.assets.Handle;

export struct LevelLoader {
    static auto operator()(const std::filesystem::path& filename) -> std::string;
};

using CachedLevelLoader = ddge::exec::accessors::assets::Cached<LevelLoader>;

using namespace ddge::exec::accessors;

export auto load_levels(
    State<GlobalState> global_state,   //
    CachedLevelLoader  level_loader
) -> void;

module :private;

auto LevelLoader::operator()(const std::filesystem::path& filename) -> std::string
{
    std::ifstream file(
        std::filesystem::path{ "assets" } / "levels" / filename,
        std::ios::in | std::ios::binary
    );
    if (!file) {
        return {};
    }
    std::ostringstream contents;
    contents << file.rdbuf();
    return contents.str();
}

auto load_levels(State<GlobalState> global_state, CachedLevelLoader level_loader) -> void
{
    std::vector<ddge::assets::Handle<std::string>> levels;
    std::vector<ddge::assets::Handle<std::string>> level_spawners;
    levels.emplace_back(level_loader->load("debug"));
    level_spawners.emplace_back(level_loader->load("debug-spawners"));

    if (!global_state.has_value()) {
        global_state.emplace(
            GlobalState{ .levels         = std::move(levels),
                         .level_spawners = std::move(level_spawners) }
        );
    }
    else {
        global_state->levels         = std::move(levels);
        global_state->level_spawners = std::move(level_spawners);
    }
}
