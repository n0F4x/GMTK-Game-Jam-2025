module;

#include <string>
#include <string_view>

#include <SFML/Graphics.hpp>

export module logic.dialog.Dialog;

import components.SFMLComponent;

import window.Window;

export class Dialog final : public SFDrawable {
public:
    Dialog(
        const sf::Font&       font,
        std::string_view      text,
        const sf::Texture&    background,
        const window::Window& window
    );

    void draw(window::Window& window) const override;

private:
    sf::Sprite m_background;
    sf::Text   m_text;
};

module :private;

Dialog::Dialog(
    const sf::Font&        font,
    const std::string_view text,
    const sf::Texture&     background,
    const window::Window&  window
)
    : m_background{ background },
      m_text{ font, std::string{ text } }
{
    const sf::Vector2f origin{ static_cast<float>(window.getSize().x / 2),
                               window.getSize().y - m_text.getGlobalBounds().size.y / 2.f
                                   - 50.f };

    m_background.setPosition(origin);
    m_text.setPosition(origin);
}

void Dialog::draw(window::Window& window) const
{
    window.draw(m_background);
    window.draw(m_text);
}
