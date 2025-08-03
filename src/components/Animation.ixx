module;

#include <span>
#include <vector>

#include <SFML/System/Vector2.hpp>

export module components.Animation;

import utility.Strong;

import states.Textures;

export class Animation {
public:
    enum struct FaceDirection {
        eRight,
        eLeft,
    };

    Animation(
        std::span<const Textures::Texture> textures,
        unsigned                           id,
        sf::Vector2f                       drawable_size,
        FaceDirection                      face_direction
    );

    [[nodiscard]]
    auto current_texture() const noexcept -> const Textures::Texture&;
    [[nodiscard]]
    auto id() const noexcept -> unsigned;
    [[nodiscard]]
    auto face_direction() const noexcept -> FaceDirection;
    [[nodiscard]]
    auto drawable_size() const noexcept -> sf::Vector2f;

    auto update() -> void;
    auto switch_face_direction() -> void;

private:
    std::vector<Textures::Texture> m_textures;
    size_t                         m_current_texture_index{};
    unsigned                       m_id;
    FaceDirection                  m_face_direction{ FaceDirection::eRight };

    // the size of a unit square (should be always 32, 32)
    sf::Vector2f m_drawable_size{ 32, 32 };
};

Animation::Animation(
    std::span<const Textures::Texture> textures,
    const unsigned                     id,
    sf::Vector2f                       drawable_size,
    const FaceDirection                face_direction
)
    : m_textures{ std::from_range, textures },
      m_id{ id },
      m_face_direction{ face_direction },
      m_drawable_size{ drawable_size }
{}

auto Animation::current_texture() const noexcept -> const Textures::Texture&
{
    return m_textures[m_current_texture_index];
}

auto Animation::id() const noexcept -> unsigned
{
    return m_id;
}

auto Animation::face_direction() const noexcept -> FaceDirection
{
    return m_face_direction;
}

auto Animation::drawable_size() const noexcept -> sf::Vector2f
{
    return m_drawable_size;
}

auto Animation::update() -> void
{
    m_current_texture_index = (m_current_texture_index + 1) % m_textures.size();
}

auto Animation::switch_face_direction() -> void
{
    for (Textures::Texture& texture : m_textures) {
        texture = texture.mirror_horizontal();
    }

    m_face_direction = m_face_direction == FaceDirection::eRight ? FaceDirection::eLeft
                                                                 : FaceDirection::eRight;
}
