module;

#include <random>

export module components.AttackAttributes;

export struct AttackAttributes {
    float damage{ 10 };
    float crit_chance{ 0.1f };       // 10% chance to crit
    float crit_multiplier{ 1.2f };   // crit deals double damage

    [[nodiscard]]
    float roll_damage() const;
};

module :private;

float AttackAttributes::roll_damage() const
{
    static std::random_device        rd;
    static std::mt19937              gen(rd());
    std::uniform_real_distribution<> dis(0.f, 1.f);

    const float random = dis(gen);

    float damage = this->damage;
    if (crit_chance >= random) {
        damage *= crit_multiplier;
    }
    return damage;
}
