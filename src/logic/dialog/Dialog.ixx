module;

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
