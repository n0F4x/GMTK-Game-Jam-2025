module;

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include <GL/glew.h>


export module gl.VertexBufs;

namespace gl {


export struct VertexBufs {
    // buffers for stuff contained in Atlas :)
    GLuint vao{};
    GLuint vbo[2]{};
    bool   init = false;

    // 3 coordinates: x/y are for position, z for depth
    std::vector<sf::Vector3f> vertexArray;

    // and the texture coordinates. Textures are a pixel-art grid, these will always be
    // integers.
    std::vector<sf::Vector2f> textArray;

    void initialize()
    {
        init = true;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(2, vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    }

    VertexBufs() = default;

    VertexBufs(const VertexBufs&)            = delete;
    VertexBufs& operator=(const VertexBufs&) = delete;

    VertexBufs(VertexBufs&&)            = default;
    VertexBufs& operator=(VertexBufs&&) = default;

    void clear()
    {
        vertexArray.clear();
        textArray.clear();
    }

    ~VertexBufs()
    {
        if (init) {
            glDeleteBuffers(2, vbo);
            glDeleteVertexArrays(1, &vao);
        }
    }
};
}   // namespace gl
