module;

#include <span>

#include <SFML/Window.hpp>

export module logic.pause_or_resume_game_on_input;

import extensions.scheduler.accessors;

import events.GamePauseEvent;
import events.WindowEvent;

using namespace extensions::scheduler::accessors;

export auto pause_or_resume_game_on_input(
    const Reader<WindowEvent>      window_event_reader,
    const Recorder<GamePauseEvent> recorder
) -> void
{
    for (const WindowEvent& window_event : window_event_reader.read()) {
        if (const sf::Event::KeyPressed* key_pressed_event =
                window_event.getIf<sf::Event::KeyPressed>();
            key_pressed_event != nullptr)
        {
            switch (key_pressed_event->code) {
                case sf::Keyboard::Key::P: recorder.record(GamePause::ePause); break;
                case sf::Keyboard::Key::R: recorder.record(GamePause::eResume); break;
                default:                   break;
            }
        }
    }
}
