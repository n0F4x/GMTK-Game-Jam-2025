module;


export module ui.initUI;

import extensions.scheduler.accessors.ecs.Registry;
import extensions.scheduler.accessors.states.State;
import common.Fonts;


using namespace extensions::scheduler::accessors;

namespace ui {

export auto createUI(Registry registry, State<Fonts> fonts) -> void;

}   // namespace ui
