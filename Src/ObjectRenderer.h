#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

class ObjectRenderer
{

public:
	void Draw();
	void CreateCube();
	void CreateRectangle();
	void CreateDoubleTriangles();
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int glType, const std::string& source);

private:

	GLfloat cubeVertices[56] = {
	// Position			  // Color
	-0.5f, -0.5f, -0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 0
	 0.5f, -0.5f, -0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 1
	 0.5f,  0.5f, -0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 2
	-0.5f,  0.5f, -0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 3
	-0.5f, -0.5f,  0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 4
	 0.5f, -0.5f,  0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 5
	 0.5f,  0.5f,  0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 6
	-0.5f,  0.5f,  0.5f,  1.0, 0.0, 0.0, 1.0,// Vertex 7
	};

	GLuint cubeIndices[24] = {
	0, 1, 1, 2, 2, 3, 3, 0, // Bottom Face
	4, 5, 5, 6, 6, 7, 7, 4, // Top Face
	0, 4, 1, 5, 2, 6, 3, 7  // Side Edges
	};

	GLfloat recVertices [28] = {
	// Position			 // Color
	+0.5f, +0.5f, 0.0f,  1.0, 0.0, 0.0, 1.0,// top right
	+0.5f, -0.5f, 0.0f,  1.0, 0.0, 0.0, 1.0,// bottom right
	-0.5f, -0.5f, 0.0f,  1.0, 0.0, 1.0, 1.0,// bottom left
	-0.5f, +0.5f, 0.0f,  0.0, 0.0, 1.0, 1.0,// top left
	};

	GLuint recIndices [6] = {
	0, 1, 3, // Top right tri
	1, 2, 3 // Bottom left tri
	};

	GLfloat doubleTriangleVerticies[42] =
	{
		// Triangle 1
		// Position		    //Color
		-1.0, +1.0, +0.5f,  0.0, 1.0, 0.0, 1.0,
		 0.0, -1.0, +0.5f,  0.0, 1.0, 0.0, 1.0,
		+1.0, +1.0, +0.5f,  0.0, 1.0, 0.0, 1.0,

		// Triangle 2
		// Position		    //Color
		 0.0, +1.0, +0.5f,  1.0, 0.0, 1.0, 1.0,
		-1.0, -1.0, +0.5f,  1.0, 0.0, 1.0, 1.0,
		+1.0, -1.0, +0.5f,  1.0, 0.0, 1.0, 1.0
	};

	GLuint doubleTriangleIndicies[6] =
	{
		// Triangle 1
		0, 1, 2,
		
		// Triangle 2
		3, 4, 5
	};

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};

