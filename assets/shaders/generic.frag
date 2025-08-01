#version 330
precision highp float;	// normal floats, makes no difference on desktop computers

uniform sampler2D textureUnit;

in vec2 uv;		// uniform variable, the color of the primitive
out vec4 outColor;		// computed color of the current pixel

void main() {
    vec4 texel = texture(textureUnit, uv); // no effects, just texture

    if(texel.a < 0.05) {  // some alpha testing
        //outColor = vec4(uv.x, uv.y, abs(1-uv.x-uv.y), 1);
        discard;
    } else {
        outColor = texel;
    }
}