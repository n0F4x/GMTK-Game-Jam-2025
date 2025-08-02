module;

#include <SFML/Graphics/Font.hpp>

export module common.Fonts;

import core.assets;

export struct Fonts {
    core::assets::Handle<sf::Font> std_font;
};
