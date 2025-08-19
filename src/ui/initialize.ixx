export module ui.initialize;

import ddge.modules.execution.accessors;

import events.GamePauseEvent;
import events.SpawnDialogEvent;

using namespace ddge::exec::accessors;

namespace ui {

export auto initialize(Recorder<SpawnDialogEvent> dialog_recorder, Recorder<GamePauseEvent> pause_recorder) -> void;

}   // namespace ui
