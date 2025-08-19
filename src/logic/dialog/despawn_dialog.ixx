export module logic.dialog.despawn_dialog;

import ddge.modules.execution.accessors;

import events.GamePauseEvent;
import events.WindowEvent;

import states.DialogState;

using namespace ddge::exec::accessors;

export auto despawn_dialog(
    Reader<WindowEvent>      window_event_reader,
    Registry                 registry,
    State<DialogState>       dialog_state,
    Recorder<GamePauseEvent> pause_recorder
) -> void;
