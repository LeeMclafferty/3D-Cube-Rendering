#pragma once

#include <GL/glew.h>
#include "ShapeData.h"

namespace PremadeShapes
{
	Vertex cubeVertices[8] = {
		// Position							// Color 
		glm::vec3(-0.5f, -0.5f, -0.5f),		Color(0.6f, 0.3f, 0.0f, 1.0f), // Vertex 0
		glm::vec3(0.5f, -0.5f, -0.5f),		Color(0.5f, 0.0f, 0.8f, 1.0f), // Vertex 1
		glm::vec3(0.5f,  0.5f, -0.5f),		Color(0.0f, 0.5f, 0.7f, 1.0f), // Vertex 2
		glm::vec3(-0.5f,  0.5f, -0.5f),		Color(0.6f, 0.3f, 0.0f, 1.0f), // Vertex 3
		glm::vec3(-0.5f, -0.5f,  0.5f),		Color(0.5f, 0.0f, 0.8f, 1.0f), // Vertex 4
		glm::vec3(0.5f, -0.5f,  0.5f),		Color(0.0f, 0.5f, 0.7f, 1.0f), // Vertex 5
		glm::vec3(0.5f,  0.5f,  0.5f),		Color(0.6f, 0.3f, 0.0f, 1.0f), // Vertex 6
		glm::vec3(-0.5f,  0.5f,  0.5f),		Color(0.5f, 0.0f, 0.8f, 1.0f), // Vertex 7
	};

	GLuint cubeIndices[36] = {
		// Front face
		0, 1, 2, 
		0, 2, 3,
		// Back face
		4, 5, 6, 
		4, 6, 7,
		// Left face
		0, 3, 7, 
		0, 7, 4,
		// Right face
		1, 2, 6, 
		1, 6, 5,
		// Top face
		3, 2, 6, 
		3, 6, 7,
		// Bottom face
		0, 1, 5, 
		0, 5, 4
	};

	Vertex recVertices[28] = {
		// Position						// Color
		glm::vec3(+0.5f, -0.5f, 0.0f),  Color(1.0f, 0.0f, 0.0f, 1.0f), // bottom right
		glm::vec3(+0.5f, +0.5f, 0.0f),  Color(1.0f, 0.0f, 0.0f, 1.0f), // top right
		glm::vec3(-0.5f, -0.5f, 0.0f),  Color(1.0f, 0.0f, 1.0f, 1.0f), // bottom left
		glm::vec3(-0.5f, +0.5f, 0.0f),  Color(0.0f, 0.0f, 1.0f, 1.0f), // top left
	};

	GLuint recIndices[6] = {
	0, 1, 3, // Top right tri
	1, 2, 3 // Bottom left tri
	};

	Vertex doubleTriangleVerticies[42] =
	{
		// Triangle 1
		// Position						//Color
		glm::vec3(-1.0, +1.0, -0.5f),  Color(0.0f, 1.0f, 0.8f, 1.0f), // Left
		glm::vec3(0.0, -1.0, -0.5f),   Color(0.0f, 1.0f, 0.0f, 1.0f), // Bottom
		glm::vec3(+1.0, +1.0, -0.5f),  Color(0.0f, 1.0f, 0.4f, 1.0f), // Right

		// Triangle 2
		// Position		    //Color
		glm::vec3(0.0, +1.0, -0.9f),  Color(0.8, 0.4, 1.0, 1.0), // Top
		glm::vec3(-1.0, -1.0, +0.5f), Color(0.7, 0.0, 1.0, 1.0), // Left
		glm::vec3(+1.0, -1.0, +0.5f), Color(0.5, 0.6, 1.0, 1.0), // Right
	};

	GLuint doubleTriangleIndicies[6] =
	{
		// Triangle 1
		0, 1, 2,

		// Triangle 2
		3, 4, 5
	};

	Vertex triangleVerticies[3] =
	{
		// Triangle 2
		// Position						//Color
		glm::vec3(0.0, +1.0, +0.5f),  Color(0.1, 0.6, 1.0, 1.0), // Top
		glm::vec3(-1.0, -1.0, +0.5f),  Color(1.0, 0.0, 0.6, 1.0), // Left
		glm::vec3(+1.0, -1.0, +0.5f),  Color(0.6, 0.0, 1.0, 1.0), // Right
	};

	GLuint triangleIndicies[3] =
	{
		0, 1 ,2,
	};
};

