export module logic.dialog.update_dialogs;

import ddge.modules.execution;

import logic.dialog.despawn_dialog;
import logic.dialog.spawn_dialog;

export inline const auto update_dialogs =   //
    ddge::exec::start_as(despawn_dialog)   //
        .then(spawn_dialog);
