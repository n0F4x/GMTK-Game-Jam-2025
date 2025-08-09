module;

#include <chrono>
#include <type_traits>

export module common.AnimationTimer;

import modules.time.FixedTimer;

using namespace std::chrono_literals;

inline constexpr std::chrono::duration animation_tick_time{ 1s / 12.0 };

export using AnimationTimer = modules::time::FixedTimer<
    std::remove_cvref_t<decltype(animation_tick_time)>,
    animation_tick_time.count()>;
