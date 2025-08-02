export module common.load_fonts;

import common.Fonts;
import common.FontLoader;
import extensions.scheduler;

using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;

using CachedFontLoader = extensions::scheduler::accessors::assets::Cached<FontLoader>;

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
