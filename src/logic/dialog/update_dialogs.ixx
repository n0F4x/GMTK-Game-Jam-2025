export module logic.dialog.update_dialogs;

import extensions.scheduler;

import logic.dialog.despawn_dialog;
import logic.dialog.spawn_dialog;

export inline const auto update_dialogs =   //
    extensions::scheduler::start_as(despawn_dialog)   //
        .then(spawn_dialog);
