export module ui.initialize;

import ddge.modules.scheduler.accessors;

import events.GamePauseEvent;
import events.SpawnDialogEvent;

using namespace ddge::scheduler::accessors;

namespace ui {

export auto initialize(Recorder<SpawnDialogEvent> dialog_recorder, Recorder<GamePauseEvent> pause_recorder) -> void;

}   // namespace ui
