#version 330
precision highp float;// normal floats, makes no difference on desktop computers

out vec2 uv;

uniform mat4 MVP;// uniform variable, the Model-View-Projection transformation matrix
uniform vec2 ATLAS_SIZE;

layout(location = 0) in vec3 vp;// Varying input: vp = vertex position is expected in attrib array 0
layout(location = 1) in vec2 vuv;// vertex uv position

void main() {
    vec4 p = MVP * vec4(vp.x, vp.y, vp.z, 1); // transform vp from modeling space to normalized device space
    float z = vp.z - (vp.y * 0.05);
    gl_Position = vec4(p.x, p.y, z*.1, p.w);
    uv = vuv / ATLAS_SIZE;
}