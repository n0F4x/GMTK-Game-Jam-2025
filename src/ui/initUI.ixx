module;


export module ui.initUI;

import extensions.scheduler.accessors.ecs.Registry;

using namespace extensions::scheduler::accessors::ecs;

namespace ui {
export auto createUI(Registry registry) -> void;
}   // namespace ui
