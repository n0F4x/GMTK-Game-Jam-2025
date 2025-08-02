module;

#include <SFML/Graphics/Font.hpp>

export module states.Fonts;

import core.assets;

export struct Fonts {
    core::assets::Handle<sf::Font> std_font;
};
