#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class ObjectRenderer
{

public:
	void CreateCube();
	void Draw();
	void CreateRectangle();
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int glType, const std::string& source);

private:

	GLfloat cubeVertices[48] = {
	-0.5f, -0.5f, -0.5f, 1.0, 0.0, 0.0,// Vertex 0
	 0.5f, -0.5f, -0.5f, 1.0, 0.0, 0.0,// Vertex 1
	 0.5f,  0.5f, -0.5f, 1.0, 0.0, 0.0,// Vertex 2
	-0.5f,  0.5f, -0.5f, 1.0, 0.0, 0.0,// Vertex 3
	-0.5f, -0.5f,  0.5f, 1.0, 0.0, 0.0,// Vertex 4
	 0.5f, -0.5f,  0.5f, 1.0, 0.0, 0.0,// Vertex 5
	 0.5f,  0.5f,  0.5f, 1.0, 0.0, 0.0,// Vertex 6
	-0.5f,  0.5f,  0.5f, 1.0, 0.0, 0.0,// Vertex 7
	};

	GLuint cubeIndices[24] = {
	0, 1, 1, 2, 2, 3, 3, 0, // Bottom Face
	4, 5, 5, 6, 6, 7, 7, 4, // Top Face
	0, 4, 1, 5, 2, 6, 3, 7  // Side Edges
	};

	float recVertices[12] = {
	0.5f, 0.5f, 0.0f, // top right
	0.5f, -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f // top left
	};

	unsigned int recIndices[6] = {
	0, 1, 3, // Top right tri
	1, 2, 3 // Bottom left tri
	};

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};

