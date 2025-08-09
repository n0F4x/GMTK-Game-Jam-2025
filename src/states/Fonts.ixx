module;

#include <SFML/Graphics/Font.hpp>

export module states.Fonts;

import modules.assets;

export struct Fonts {
    modules::assets::Handle<sf::Font> std_font;
};
