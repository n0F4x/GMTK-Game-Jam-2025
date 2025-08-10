module;

#include <SFML/Graphics/Font.hpp>

export module states.Fonts;

import ddge.modules.assets;

export struct Fonts {
    ddge::assets::Handle<sf::Font> std_font;
};
