module;

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

export module gl.render;

import extensions.scheduler.accessors.ecs.Query;
import extensions.scheduler.accessors.resources.Resource;
import extensions.scheduler.accessors.states.State;
import common.Drawable;
import common.Position;
import window.Window;
import common.GlobalState;
import common.Shaders;
import common.Textures;
import gl.VertexBufs;

using namespace extensions::scheduler::accessors::ecs;
using namespace extensions::scheduler::accessors::resources;
using namespace extensions::scheduler::accessors::states;
using namespace window;

namespace gl {

export auto init_draw(Resource<VertexBufs>& bufs) -> void;

export auto draw_world(
    Query<Position, Drawable> drawable_query,
    Resource<Window>          window,
    State<GlobalState>        global_state,
    State<Shaders>            shaders,
    State<Textures>           textures,
    Resource<VertexBufs>&     vertexBufs
) -> void;
}   // namespace gl

export auto initialize() -> void;

module :private;

auto gl::init_draw(Resource<VertexBufs>& bufs) -> void
{
    bufs->clear();
}

sf::Glsl::Mat3 calculate_MVP(const Window& window, const GlobalState& global_state)
{
    float unit = 1;// / 20;

    float array[] = { unit, 0,    0,   // stuff (keep this comment here)
                      0,    unit, 0,   // stuff
                      0,    0,    unit };

    sf::Glsl::Mat3 camera{ array };
    // sf::Transform::translate() // TODO Camera transfrom (I'll do once I have render!)
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
    Resource<VertexBufs>&           vertexBufs
) -> void
{
    if (!global_state.has_value()) {
        return;   // no camera = no render
    }

    if (!window->setActive(true)) {
        std::cerr << "Cannot bind window" << std::endl;
    }

    shaders->generic_draw->setUniform("MVP", calculate_MVP(window.get(), *global_state));

    // GL config
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();

    // smooth downscaling (if ever needed)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // pixel game should look pixelated.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    sf::Shader::bind(shaders->generic_draw.get());


    sf::Texture::bind(textures->atlas.get());
    shaders->generic_draw->setUniform(
        "ATLAS_SIZE", sf::Glsl::Vec2(textures->atlas->getSize())
    );
    shaders->generic_draw->setUniform("MVP", calculate_MVP(window.get(), *global_state));


    std::vector<sf::Vector3f>& vertexBuf  = vertexBufs->vertexArray;
    std::vector<sf::Vector2i>& textureBuf = vertexBufs->textArray;
    const int                  begin      = vertexBuf.size();


    drawable_query.for_each([&](const Position position, const Drawable& drawable) {
        sf::Vector2f zeroPos = position.get()
                             - drawable.size.componentWiseMul({ .5, .5 });


        const float layer = drawable.layer + 0.01 * zeroPos.y;

        vertexBuf.emplace_back(zeroPos << layer);
        vertexBuf.emplace_back(zeroPos.x + drawable.size.x, zeroPos.y, layer);
        vertexBuf.emplace_back(zeroPos + drawable.size << layer);
        vertexBuf.emplace_back(zeroPos << layer);
        vertexBuf.emplace_back(zeroPos + drawable.size << layer);
        vertexBuf.emplace_back(zeroPos.x, zeroPos.y + drawable.size.y, layer);

        const Textures::Texture texture = drawable.texture;

        textureBuf.emplace_back(texture.pos);
        textureBuf.emplace_back(texture.pos.x + texture.size.x, texture.pos.y);
        textureBuf.emplace_back(texture.pos + texture.size);
        textureBuf.emplace_back(texture.pos);
        textureBuf.emplace_back(texture.pos + texture.size);
        textureBuf.emplace_back(texture.pos.x, texture.pos.y + texture.size.y);
    });

    const int end  = vertexBuf.size();
    const int size = end - begin;
    assert(size % 6 == 0);

    // bind
    glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), vertexBuf.data());
    glTexCoordPointer(2, GL_INT, 2 * sizeof(GLint), textureBuf.data());

    glDrawArrays(GL_TRIANGLES, begin, size);


    if (!window->setActive(false)) {
        std::cerr << "Cannot bind window" << std::endl;
    }
}
