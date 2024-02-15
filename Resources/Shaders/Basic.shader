#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

uniform mat4 modelTransformMatrix;
uniform mat4 projectionMatrix;

out vec4 vertexColor;

void main()
{
	vec4 vertexPos = vec4(aPos, 1.0);
	vec4 newPos = modelTransformMatrix * vertexPos;
	vec4 projectedPos = projectionMatrix * newPos;
	gl_Position = projectedPos;
	vertexColor = color;
};

#shader fragment
#version 330 core
out vec4 FragColor;
in vec4 vertexColor;

void main()
{
	FragColor = vertexColor;
};