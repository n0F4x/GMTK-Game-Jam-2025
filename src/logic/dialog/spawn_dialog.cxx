module;

#include <cassert>
#include <memory>
#include <ranges>
#include <span>

#include <SFML/Graphics.hpp>

module logic.dialog.spawn_dialog;

import modules.ecs;
import modules.scheduler.accessors;

import components.SFMLComponent;

import events.SpawnDialogEvent;

import logic.dialog.Dialog;

import states.DialogState;
import states.Fonts;
import states.Textures;

import window.Window;

using namespace modules::scheduler::accessors;

auto spawn_dialog(
    const Reader<SpawnDialogEvent> reader,
    const Registry                 registry,
    const State<DialogState>       dialog_state,
    const State<Fonts>             fonts,
    const State<Textures>          textures,
    const Resource<window::Window> window
) -> void
{
    assert(fonts.has_value());

    const sf::Font& font{ *fonts->std_font };

    for (const SpawnDialogEvent& spawn_dialog_event : std::views::reverse(reader.read()))
    {
        const modules::ecs::ID id = registry->create(
            SFMLComponent{ std::make_shared<Dialog>(
                font,
                spawn_dialog_event.text,
                spawn_dialog_event.style == SpawnDialogEvent::Style::eOverworld
                    ? *textures->overworld_dialog
                    : *textures->hell_dialog,
                window.get()
            ) }
        );

        if (!dialog_state.has_value()) {
            dialog_state.emplace().dialog_ids.push(id);
        }
        else {
            dialog_state->dialog_ids.push(id);
        }
    }
}
