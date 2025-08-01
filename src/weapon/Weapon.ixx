export module weapon.Weapon;

export struct Weapon {
    float damage{ 10 };
    float range{ 400 };
    float projectile_speed{ 10 };
    int ammo{ 30 };
    int firing_rate_ms {500};
};