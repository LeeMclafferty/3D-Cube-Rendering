#pragma once

#include <GL/glew.h>
#include "ShapeData.h"

namespace PremadeShapes
{
	Vertex cubeVertices[56] = {
		// Position							// Color 
		glm::vec3(-0.5f, -0.5f, -0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 0
		glm::vec3(0.5f, -0.5f, -0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 1
		glm::vec3(0.5f,  0.5f, -0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 2
		glm::vec3(-0.5f,  0.5f, -0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 3
		glm::vec3(-0.5f, -0.5f,  0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 4
		glm::vec3(0.5f, -0.5f,  0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 5
		glm::vec3(0.5f,  0.5f,  0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 6
		glm::vec3(-0.5f,  0.5f,  0.5f),		Color(1.0f, 0.0f, 0.0f, 1.0f), // Vertex 7
	};

	GLuint cubeIndices[24] = {
		0, 1, 1, 2, 2, 3, 3, 0, // Bottom Face
		4, 5, 5, 6, 6, 7, 7, 4, // Top Face
		0, 4, 1, 5, 2, 6, 3, 7  // Side Edges
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

	Vertex triangleVerticies[42] =
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

