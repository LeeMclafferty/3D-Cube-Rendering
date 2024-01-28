#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Engine
{

public:
	Engine(class GLFWwindow* glWin);
	void MainLoop();

private:
	class GLFWwindow* window;

	// Will be moved out of engine later.
	void CreateCube();

	GLfloat cubeVertices[24] = {
	-0.5f, -0.5f, -0.5f, // Vertex 0
	 0.5f, -0.5f, -0.5f, // Vertex 1
	 0.5f,  0.5f, -0.5f, // Vertex 2
	-0.5f,  0.5f, -0.5f, // Vertex 3
	-0.5f, -0.5f,  0.5f, // Vertex 4
	 0.5f, -0.5f,  0.5f, // Vertex 5
	 0.5f,  0.5f,  0.5f, // Vertex 6
	-0.5f,  0.5f,  0.5f  // Vertex 7
	};

	GLuint cubeIndices[24] = {
	0, 1, 1, 2, 2, 3, 3, 0, // Bottom Face
	4, 5, 5, 6, 6, 7, 7, 4, // Top Face
	0, 4, 1, 5, 2, 6, 3, 7  // Side Edges
	};

	void Draw();

	// Testing
	GLfloat triangleVerts[9] =
	{
		+0.0f, +1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		+1.0f, -1.0f, 0.0f
	};

	void CreateTriangle();

	float squareVertices[12] = {
	0.5f, 0.5f, 0.0f, // top right
	0.5f, -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f // top left
	};

	unsigned int squareIndices[6] = {
	0, 1, 3, 
	1, 2, 3 
	};

	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int glType, const std::string& source);

	std::string vertexShader =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	std::string fragmentShader =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	GLuint shaderProgram;
};

