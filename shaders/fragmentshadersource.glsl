#version 330 core
out vec4 fragColor;

in vec2 texCoord;

uniform bool useTexture;
uniform sampler2D ourTexture;
uniform vec3 color;

void main()
{
    if (useTexture)
    {
        fragColor = texture(ourTexture, texCoord);
    }
    else
    {
        fragColor = vec4(color, 1.0f);
    }
}