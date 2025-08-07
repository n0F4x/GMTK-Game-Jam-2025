export module logic.progress_animations;

import extensions.scheduler.accessors;

import components.Animation;
import components.Drawable;

using namespace extensions::scheduler::accessors;

export auto progress_animations(Query<Animation, Drawable>&) -> void;
