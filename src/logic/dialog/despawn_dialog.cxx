module;

#include <print>
#include <span>
#include <stack>

#include <SFML/Window.hpp>

module logic.dialog.despawn_dialog;

import ddge.modules.ecs;
import ddge.modules.scheduler.accessors;

import events.GamePauseEvent;
import events.WindowEvent;

import states.DialogState;

using namespace ddge::scheduler::accessors;

auto pop_dialog(ddge::ecs::Registry& registry, DialogState& dialog_state) -> void
{
    const ddge::ecs::ID id{ dialog_state.dialog_ids.top() };
    registry.destroy(id);
    dialog_state.dialog_ids.pop();
}

auto despawn_dialog(
    const Reader<WindowEvent>      window_event_reader,
    const Registry                 registry,
    const State<DialogState>       dialog_state,
    const Recorder<GamePauseEvent> pause_recorder
) -> void
{
    for (const sf::Event& window_event : window_event_reader.read()) {
        if (const auto* mouse_button_released{
                window_event.getIf<sf::Event::MouseButtonReleased>() };
            mouse_button_released != nullptr)
        {
            if (dialog_state.has_value()) {
                pop_dialog(registry.get(), *dialog_state);
                if (dialog_state->dialog_ids.empty()) {
                    dialog_state.reset();
                    pause_recorder.record(GamePauseEvent{ .type = GamePause::eResume });
                }
            }
        }
    }
}
