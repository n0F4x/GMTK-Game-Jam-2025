export module logic.dialog.update_dialogs;

import core.scheduler;

import logic.dialog.despawn_dialog;
import logic.dialog.spawn_dialog;

export inline constexpr auto update_dialogs =   //
    core::scheduler::start_as(despawn_dialog)   //
        .then(spawn_dialog);
