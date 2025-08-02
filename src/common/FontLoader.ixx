module;

#include <filesystem>

#include <SFML/Graphics.hpp>

export module common.FontLoader;

export struct FontLoader {
    static auto operator()(const std::filesystem::path& filename) -> sf::Font;
};

module :private;

auto FontLoader::operator()(const std::filesystem::path& filename) -> sf::Font
{
    return sf::Font(std::filesystem::path{ "assets" } / "fonts" / filename);
}
