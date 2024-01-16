#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine
{

public:
	Engine(class GLFWwindow* glWin);
	void MainLoop();

private:
	class GLFWwindow* window;

	// Will be moved out of engine later.
	void DrawCube();

	float cubeVertices[24] = {
	-0.5f, -0.5f, -0.5f, // Vertex 0
	 0.5f, -0.5f, -0.5f, // Vertex 1
	 0.5f,  0.5f, -0.5f, // Vertex 2
	-0.5f,  0.5f, -0.5f, // Vertex 3
	-0.5f, -0.5f,  0.5f, // Vertex 4
	 0.5f, -0.5f,  0.5f, // Vertex 5
	 0.5f,  0.5f,  0.5f, // Vertex 6
	-0.5f,  0.5f,  0.5f  // Vertex 7
	};

	unsigned int cubeIndices[24] = {
	0, 1, 1, 2, 2, 3, 3, 0, // Bottom Face
	4, 5, 5, 6, 6, 7, 7, 4, // Top Face
	0, 4, 1, 5, 2, 6, 3, 7  // Side Edges
	};

	const char* vertexShaderSource = R"glsl(
		#version 330 core
		layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 projection;

		void main()
		{
			gl_Position = projection * view * model * vec4(aPos, 1.0); // Transforms vertex position to clip space
		}
		)glsl";

	const char* fragmentShaderSource = R"glsl(
		#version 330 core
		out vec4 FragColor;

		void main()
		{
			FragColor = vec4(1.0, 1.0, 1.0, 1.0); // Set the color to white
		}
		)glsl";


};

