module;

#include <chrono>
#include <type_traits>

export module spawner.SpawnerTimer;

import modules.time.FixedTimer;

using namespace std::chrono_literals;

inline constexpr std::chrono::duration spawn_interval{ 5s };

export using SpawnerTimer = modules::time::
    FixedTimer<std::remove_cvref_t<decltype(spawn_interval)>, spawn_interval.count()>;
