module;

#include <chrono>
#include <type_traits>

export module window.DisplayTimer;

import modules.time.FixedTimer;

using namespace std::chrono_literals;

namespace window {

inline constexpr std::chrono::duration display_time{ 1s / 60.0 };

export using DisplayTimer = modules::time::
    FixedTimer<std::remove_cvref_t<decltype(display_time)>, display_time.count()>;

}   // namespace window
