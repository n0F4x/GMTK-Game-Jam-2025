module;

#include <filesystem>

#include <SFML/Graphics.hpp>

export module common.TextureLoader;

import core.assets.asset_c;

export struct TextureLoader {
    static auto operator()(const std::filesystem::path& filename) -> sf::Texture;
};

module :private;

auto TextureLoader::operator()(const std::filesystem::path& filename) -> sf::Texture
{
    return sf::Texture{ std::filesystem::path{ "assets" } / "textures" / filename };
}
