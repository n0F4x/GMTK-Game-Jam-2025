module;

#include <SFML/System/Vector2.hpp>

module logic.progress_animations;

import extensions.scheduler.accessors;

import components.Animation;

using namespace extensions::scheduler::accessors;

auto progress_animations(Query<Animation, Drawable> entities) -> void
{
    entities.for_each([](Animation& animation, Drawable& drawable) -> void {
        animation.current_texture_index = (animation.current_texture_index + 1)
                                        % animation.textures.size();
        drawable.texture = animation.textures[animation.current_texture_index];
        drawable.size    = sf::Vector2f{ drawable.texture.size }.componentWiseDiv(
            sf::Vector2f{ animation.drawable_size }
        );
    });
}
