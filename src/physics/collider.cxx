module;

#include <cmath>

#include <SFML/System/Vector2.hpp>

module physics.collider;

using namespace sf;

constexpr float ignoreDistance = 0.15f;

auto physics::collision_check(
    const Vector2f entity_pos,
    const Hitbox   entity_hitbox,
    const Vector2f other_pos,
    const Hitbox   other_hitbox
) -> Vector2f
{
    const Vector2f delta = entity_pos - other_pos;

    const Vector2f dir(delta.x < 0 ? 1 : -1, delta.y < 0 ? 1 : -1);
    Vector2f       offset(std::abs(delta.x), abs(delta.y));
    Vector2f       hitSize = entity_hitbox.underlying() + other_hitbox.underlying();
    hitSize                = hitSize.componentWiseMul({ .5, .5 });

    // now calculate how much these are intersecting
    offset = offset - hitSize;
    // don't store negative offset
    offset = Vector2f(offset.x < 0 ? offset.x : 0, offset.y < 0 ? offset.y : 0);
    offset = offset.componentWiseMul(dir);

    // decrement by ignore, this will help a lot on wall hitting collisions
    hitSize = hitSize - Vector2f(ignoreDistance, ignoreDistance);
    if (abs(delta.x) > hitSize.x) {
        offset.y = 0;
    }
    if (abs(delta.y) > hitSize.y) {
        offset.x = 0;
    }
    if (offset.x != 0 && offset.y != 0) {
        if (abs(offset.x) > abs(offset.y)) {
            offset.y = 0;
        } else {
            offset.x = 0;
        }
    }
    return offset;
}
