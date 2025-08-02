export module weapon.Weapon;

export struct Weapon {
    float damage{ 10 };
    float range{ 10 };
    float projectile_speed{ 0.2f };
    float crit_chance{ 0.1f }; // 10% chance to crit
    float crit_multiplier{ 1.2f }; // crit deals double damage
    int firing_rate_ms {250};
};