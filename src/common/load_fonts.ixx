export module common.load_fonts;

import states.Fonts;
import common.FontLoader;
import ddge.modules.execution;

using namespace ddge::exec::accessors;

using CachedFontLoader = Cached<FontLoader>;

export auto load_fonts(
    State<Fonts>     fontsState,   //
    CachedFontLoader font_loader
) -> void;

module :private;

auto load_fonts(const State<Fonts> fontsState, const CachedFontLoader font_loader) -> void
{
    if (!fontsState.has_value()) {
        fontsState.emplace(font_loader->load("font.ttf"));
    }
}
