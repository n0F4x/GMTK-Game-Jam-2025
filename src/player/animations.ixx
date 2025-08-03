export module player.animations;

import components.Animation;

export [[nodiscard]]
auto idle_animation_front() noexcept -> const Animation&;

export [[nodiscard]]
auto idle_animation_back() noexcept -> const Animation&;

export [[nodiscard]]
auto run_animation_front() noexcept -> const Animation&;

export [[nodiscard]]
auto run_animation_back() noexcept -> const Animation&;
