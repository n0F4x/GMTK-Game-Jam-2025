module;

#include <filesystem>
#include <fstream>

export module common.LevelLoader;

import common.GlobalState;
import extensions.scheduler;
import core.assets.Handle;

export struct LevelLoader {
    static auto operator()(const std::filesystem::path& filename) -> std::string;
};

using CachedLevelLoader = extensions::scheduler::accessors::assets::Cached<LevelLoader>;

using namespace extensions::scheduler::accessors;

export auto load_levels(
    State<GlobalState> global_state,   //
    CachedLevelLoader  level_loader
);

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

auto load_levels(State<GlobalState> global_state, CachedLevelLoader level_loader)
{
    std::vector<core::assets::Handle<std::string>> levels;
    levels.emplace_back(level_loader->load("level1.txt"));

    if (!global_state.has_value()) {
        global_state.emplace(GlobalState{ .levels = std::move(levels) });
    } else {
        global_state->levels = std::move(levels);
    }
}
