module;

#include <chrono>
#include <type_traits>

export module common.GameTimer;

import core.time.FixedTimer;

using namespace std::chrono_literals;

inline constexpr std::chrono::duration game_tick_time{ 1s / 120.0 };

export using GameTimer = core::time::
    FixedTimer<std::remove_cvref_t<decltype(game_tick_time)>, game_tick_time.count()>;
