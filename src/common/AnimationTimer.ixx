module;

#include <chrono>
#include <type_traits>

export module common.AnimationTimer;

import core.time.FixedTimer;

using namespace std::chrono_literals;

inline constexpr std::chrono::duration animation_tick_time{ 1s / 12.0 };

export class AnimationTimer : public core::time::FixedTimer<
                                  std::remove_cvref_t<decltype(animation_tick_time)>,
                                  animation_tick_time.count()> {};
