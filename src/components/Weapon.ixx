module;

#include <chrono>

export module components.Weapon;

export struct Weapon {
    float                                 projectile_speed{ 0.2f };
    int                                   firing_rate_ms{ 250 };
    std::chrono::steady_clock::time_point last_firing_time{
        std::chrono::steady_clock::now()
    };
};
