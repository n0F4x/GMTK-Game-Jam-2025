module;

#include <chrono>
#include <type_traits>

export module common.AnimationTimer;

import core.time.FixedTimer;

using namespace std::chrono_literals;

inline constexpr std::chrono::duration game_tick_time{ 1s / 12.0 };

export using AnimationTimer = core::time::
    FixedTimer<std::remove_cvref_t<decltype(game_tick_time)>, game_tick_time.count()>;
