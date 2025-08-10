module ui.initialize;

import ddge.modules.scheduler.accessors;

import events.SpawnDialogEvent;

using namespace ddge::scheduler::accessors;

auto ui::initialize(
    const Recorder<SpawnDialogEvent> dialog_recorder,
    const Recorder<GamePauseEvent>   pause_recorder
) -> void
{
    dialog_recorder.record(
        SpawnDialogEvent{
            .text  = "Welcome to Fred's Hell, player!",
            .style = SpawnDialogEvent::Style::eOverworld,
        }
    );

    dialog_recorder.record(
        SpawnDialogEvent{
            // clang-format off
            .text  = "Our protagonist Fred\nis not a fascinating or kind, angel-like\n"
                     "person, but quite the opposite.\nHe acts rudely and selfishly all\n"
                     "the time, and has a mean personality.\nConsequently, he has been\n"
                     "dragged down to hell,\nliving through the same suffering every day.",
            // clang-format on
            .style = SpawnDialogEvent::Style::eOverworld,
        }
    );

    dialog_recorder.record(
        SpawnDialogEvent{
            // clang-format off
            .text  = "Your task, player,\nis to help Fred meet with her daughter,\n"
                     "who resembling her father\ncommitted such atrocities\n"
                     "that now she lives\nin the deepest level of hell.",
            // clang-format on
            .style = SpawnDialogEvent::Style::eOverworld,
        }
    );

    pause_recorder.record(GamePauseEvent{ .type = GamePause::ePause });
}
