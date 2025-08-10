module;

#include <chrono>
#include <type_traits>

export module window.DisplayTimer;

import ddge.modules.time.FixedTimer;

using namespace std::chrono_literals;

namespace window {

inline constexpr std::chrono::duration display_time{ 1s / 60.0 };

export using DisplayTimer = ddge::time::
    FixedTimer<std::remove_cvref_t<decltype(display_time)>, display_time.count()>;

}   // namespace window
