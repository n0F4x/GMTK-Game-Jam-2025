module;

#include <filesystem>
#include <iostream>

#include <SFML/Graphics.hpp>

export module common.ShaderLoader;

export struct ShaderLoader {
    static auto operator()(const std::filesystem::path& filename) -> sf::Shader;
};

module :private;

auto appendExtension(std::filesystem::path path, const std::string& ext)
    -> std::filesystem::path
{
    return path.replace_extension(ext);
}

auto ShaderLoader::operator()(const std::filesystem::path& filename) -> sf::Shader
{
    sf::Shader shader;
    auto       commonPath = std::filesystem::path{ "assets" } / "shaders" / filename;

    if (!shader.loadFromFile(
            appendExtension(commonPath, "vert"), appendExtension(commonPath, "frag")
        ))
    {
        std::cerr << "Failed to load shader " << commonPath << std::endl;
    }

    return shader;
}
