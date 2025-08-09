export module logic.dialog.despawn_dialog;

import modules.scheduler.accessors;

import events.GamePauseEvent;
import events.WindowEvent;

import states.DialogState;

using namespace modules::scheduler::accessors;

export auto despawn_dialog(
    Reader<WindowEvent>      window_event_reader,
    Registry                 registry,
    State<DialogState>       dialog_state,
    Recorder<GamePauseEvent> pause_recorder
) -> void;
