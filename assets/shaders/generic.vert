#version 330
precision highp float;// normal floats, makes no difference on desktop computers
out vec2 uv;

uniform mat3 MVP;// uniform variable, the Model-View-Projection transformation matrix
uniform vec2 ATLAS_SIZE;

layout(location = 0) in vec3 vp;// Varying input: vp = vertex position is expected in attrib array 0
layout(location = 1) in ivec2 vuv;// vertex uv position

void main() {
    vec3 p = vec3(vp.x, vp.y, 1) * MVP;// transform vp from modeling space to normalized device space
    float z = vp.z - 0.01 * p.y;
    gl_Position = vec4(vp.x, vp.y, vp.x + vp.y, p.z);
    uv = vuv/ATLAS_SIZE;
}