export module weapon.Weapon;

export struct Weapon {
    float damage{ 10 };
    float range{ 10 };
    float projectile_speed{ 0.2f };
    int ammo{ 30 };
    int firing_rate_ms {250};
};