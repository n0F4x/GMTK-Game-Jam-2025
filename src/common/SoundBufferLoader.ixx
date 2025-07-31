module;

#include <filesystem>
#include <memory>

#include <SFML/Audio.hpp>

export module common.SoundBufferLoader;

export struct SoundBufferLoader {
    static auto operator()(const std::filesystem::path& filename)
        -> std::unique_ptr<sf::SoundBuffer>;
};

module :private;

auto SoundBufferLoader::operator()(const std::filesystem::path& filename)
    -> std::unique_ptr<sf::SoundBuffer>
{
    return std::make_unique<sf::SoundBuffer>(
        std::filesystem::path{ "assets" } / "sounds" / filename
    );
}
