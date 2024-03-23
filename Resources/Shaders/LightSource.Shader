#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

uniform mat4 modelTransformMatrix; // Model to world
uniform mat4 viewMatrix; // World to view
uniform mat4 projectionMatrix; // View to projection

out vec4 vertexColor;
void main()
{
    vec4 worldPos = modelTransformMatrix * vec4(aPos, 1.0);
    gl_Position = projectionMatrix * viewMatrix * worldPos;
    vertexColor = color;
}

#shader fragment
#version 330 core
in vec4 vertexColor;

out vec4 FragColor;

void main()
{
    FragColor = vertexColor;
};