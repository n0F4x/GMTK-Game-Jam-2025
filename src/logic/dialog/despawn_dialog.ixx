export module logic.dialog.despawn_dialog;

import extensions.scheduler.accessors;

import events.WindowEvent;

import states.DialogState;

using namespace extensions::scheduler::accessors;

export auto despawn_dialog(
    Reader<WindowEvent> window_event_reader,
    Registry            registry,
    State<DialogState>  dialog_state
) -> void;
