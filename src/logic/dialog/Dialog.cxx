module;

#include <string>
#include <string_view>

#include <SFML/Graphics.hpp>

module logic.dialog.Dialog;

import components.SFMLComponent;

import window.Window;

Dialog::Dialog(
    const sf::Font&        font,
    const std::string_view text,
    const sf::Texture&     background,
    const window::Window&  window
)
    : m_background{ background },
      m_text{ font, std::string{ text } }
{
    const sf::Vector2f origin{ window.getSize().x / 2.f, window.getSize().y - 340.f };

    m_background.setScale(sf::Vector2f{ 15.f, 10.f });
    m_background.setPosition(origin - m_background.getGlobalBounds().size / 2.f);
    m_text.setPosition(origin - m_text.getGlobalBounds().size / 2.f);
}

void Dialog::draw(window::Window& window) const
{
    window.draw(m_background);
    window.draw(m_text);
}
