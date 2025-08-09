export module logic.progress_animations;

import modules.scheduler.accessors;

import components.Animation;
import components.Drawable;

using namespace modules::scheduler::accessors;

export auto progress_animations(Query<Animation, Drawable>&) -> void;
