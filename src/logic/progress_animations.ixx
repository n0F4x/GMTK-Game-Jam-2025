export module logic.progress_animations;

import ddge.modules.scheduler.accessors;

import components.Animation;
import components.Drawable;

using namespace ddge::scheduler::accessors;

export auto progress_animations(Query<Animation, Drawable>&) -> void;
