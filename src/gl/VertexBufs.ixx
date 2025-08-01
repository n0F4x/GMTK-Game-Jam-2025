module;

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <GL/gl.h>

export module gl.VertexBufs;

namespace gl {

/*
export struct GameSprite : sf::Drawable {
    GLuint array;
    GLuint bufs[2];

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }

    GameSprite()
    {
        glGenVertexArrays(1, &array);
        glGenBuffers(1, bufs);
    }

    GameSprite(const GameSprite&)            = delete;
    GameSprite& operator=(const GameSprite&) = delete;

    GameSprite(GameSprite&&)                  = default;
    GameSprite& operator=(const GameSprite&&) = default;

    ~GameSprite() override
    {
        glDeleteBuffers(2, bufs);
        glDeleteVertexArrays(1, &array);
    }
};
*/

export struct VertexBufs {
    // buffers for stuff contained in Atlas :)

    // 3 coordinates: x/y are for position, z for depth
    std::vector<sf::Vector3f> vertexArray;

    // and the texture coordinates. Textures are a pixel-art grid, these will always be
    // integers.
    std::vector<sf::Vector2i> textArray;

    VertexBufs() = default;

    VertexBufs(const VertexBufs&)            = delete;
    VertexBufs& operator=(const VertexBufs&) = delete;

    VertexBufs(VertexBufs&&) = default;
    VertexBufs& operator=(VertexBufs&&) = default;

    void clear()
    {
        vertexArray.clear();
        textArray.clear();
    }
};
}   // namespace gl
