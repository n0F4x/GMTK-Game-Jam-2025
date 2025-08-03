export module player.animations;

import components.Animation;

export [[nodiscard]]
auto idle_animation_front(bool has_gun) noexcept -> const Animation&;

export [[nodiscard]]
auto idle_animation_back(bool has_gun) noexcept -> const Animation&;

export [[nodiscard]]
auto run_animation_front(bool has_gun) noexcept -> const Animation&;

export [[nodiscard]]
auto run_animation_back(bool has_gun) noexcept -> const Animation&;
