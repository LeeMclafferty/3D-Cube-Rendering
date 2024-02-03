#shader vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

out vec4 vertexColor;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
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