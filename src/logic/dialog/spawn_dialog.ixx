export module logic.dialog.spawn_dialog;

import ddge.modules.execution.accessors;

import events.SpawnDialogEvent;

import states.DialogState;
import states.Fonts;
import states.Textures;

import window.Window;

using namespace ddge::exec::accessors;

export auto spawn_dialog(
    Reader<SpawnDialogEvent> reader,
    Registry                 registry,
    State<DialogState>       dialog_state,
    State<Fonts>             fonts,
    State<Textures>          textures,
    Resource<window::Window> window
) -> void;
