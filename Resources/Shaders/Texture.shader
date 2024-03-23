#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 aTexCoord;


uniform mat4 modelTransformMatrix; // Model to world
uniform mat4 viewMatrix; // World to view
uniform mat4 projectionMatrix; // View to projection

out vec4 vertexColor;
out vec2 texCoord;

void main()
{
    vec4 worldPos = modelTransformMatrix * vec4(aPos, 1.0);
    gl_Position = projectionMatrix * viewMatrix * worldPos;
    vertexColor = color;
    texCoord = aTexCoord;
}

#shader fragment
#version 330 core
in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D textureImg;
uniform vec4 lightingColor;

out vec4 FragColor;

void main()
{
	FragColor = texture(textureImg, texCoord);
};