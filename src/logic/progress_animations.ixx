export module logic.progress_animations;

import ddge.modules.execution.accessors;

import components.Animation;
import components.Drawable;

using namespace ddge::exec::accessors;

export auto progress_animations(Query<Animation, Drawable>&) -> void;
