module;

#include <SFML/System/Vector2.hpp>

module logic.progress_animations;

import ddge.modules.scheduler.accessors;

import components.Animation;

using namespace ddge::scheduler::accessors;

auto progress_animations(Query<Animation, Drawable>& entities) -> void
{
    entities.for_each([](Animation& animation, Drawable& drawable) -> void {
        animation.update();
        drawable.texture = animation.current_texture();
        drawable.size    = sf::Vector2f{ drawable.texture.size }.componentWiseDiv(
            sf::Vector2f{ animation.drawable_size() }
        );
    });
}
