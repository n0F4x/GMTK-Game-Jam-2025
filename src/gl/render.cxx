module;

#include <cassert>
#include <iostream>

#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <GL/glew.h>


module gl.render;

import extensions.scheduler.accessors.ecs.Query;
import extensions.scheduler.accessors.resources.Resource;
import extensions.scheduler.accessors.states.State;
import components.Drawable;
import components.Position;
import window.Window;
import states.GlobalState;
import states.Shaders;
import states.Textures;
import gl.VertexBufs;

using namespace extensions::scheduler::accessors;
using namespace window;

auto gl::init_draw(const Resource<VertexBuffers>& vertex_buffers) -> void
{
    vertex_buffers->clear();
}

sf::Glsl::Mat4 gl::calculate_MVP(const Window& window, const GlobalState& global_state)
{
    // ~0.2, positive
    float zoom = global_state.zoom;

    auto scale = sf::Vector2f{ window.getSize() }.normalized();

    sf::Transform transform;
    transform.scale({ scale.y, scale.x });
    transform.scale({ zoom, zoom });
    transform.translate(-global_state.camera_position);

    sf::Glsl::Mat4 camera{ transform.getMatrix() };
    return camera;
}

sf::Vector3f operator<<(const sf::Vector2f& lhs, float rhs)
{
    return { lhs.x, lhs.y, rhs };
}

auto gl::draw_world(
    const Query<Position, Drawable> drawable_query,
    const Resource<Window>          window,
    const State<GlobalState>        global_state,
    const State<Shaders>            shaders,
    const State<Textures>           textures,
    const Resource<VertexBuffers>&  vertexBufs
) -> void
{
    if (!global_state.has_value()) {
        return;   // no camera = no render
    }

    if (!window->setActive(true)) {
        std::cerr << "Cannot bind window" << std::endl;
    }

    sf::Shader::bind(shaders->generic_draw.get());
    // smooth downscaling (if ever needed)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // pixel game should look pixelated.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    sf::Texture::bind(textures->atlas.get());

    shaders->generic_draw->setUniform(
        "ATLAS_SIZE", sf::Glsl::Vec2(textures->atlas->getSize())
    );
    shaders->generic_draw->setUniform("MVP", calculate_MVP(window.get(), *global_state));


    std::vector<sf::Vector3f>& vertexBuf  = vertexBufs->vertexArray;
    std::vector<sf::Vector2f>& textureBuf = vertexBufs->textArray;
    const int                  begin      = vertexBuf.size();


    drawable_query.for_each([&](const Position position, const Drawable& drawable) {
        sf::Vector2f zeroPos = position.underlying()
                             - drawable.size.componentWiseMul({ .5, .5 });


        const float layer = -drawable.layer + position->y * 0.05;

        vertexBuf.emplace_back(zeroPos << layer);
        vertexBuf.emplace_back(zeroPos.x + drawable.size.x, zeroPos.y, layer);
        vertexBuf.emplace_back(zeroPos + drawable.size << layer);
        vertexBuf.emplace_back(zeroPos << layer);
        vertexBuf.emplace_back(zeroPos + drawable.size << layer);
        vertexBuf.emplace_back(zeroPos.x, zeroPos.y + drawable.size.y, layer);

        const Textures::Texture texture = drawable.texture;

        textureBuf.emplace_back(texture.pos.x, texture.pos.y + texture.size.y);
        textureBuf.emplace_back(texture.pos + texture.size);
        textureBuf.emplace_back(texture.pos.x + texture.size.x, texture.pos.y);
        textureBuf.emplace_back(texture.pos.x, texture.pos.y + texture.size.y);
        textureBuf.emplace_back(texture.pos.x + texture.size.x, texture.pos.y);
        textureBuf.emplace_back(texture.pos);
    });

    const int end  = vertexBuf.size();
    const int size = end - begin;
    assert(size % 6 == 0);

    // bind
    glBindVertexArray(vertexBufs->vao);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufs->vbo[0]);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(sf::Vector3f) * end, vertexBuf.data(), GL_DYNAMIC_DRAW
    );

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufs->vbo[1]);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(sf::Vector2i) * end, textureBuf.data(), GL_DYNAMIC_DRAW
    );

    glDrawArrays(GL_TRIANGLES, begin, size);


    if (!window->setActive(false)) {
        std::cerr << "Cannot bind window" << std::endl;
    }
}
