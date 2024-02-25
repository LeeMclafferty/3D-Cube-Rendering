#pragma once

#include <GL/glew.h>
#include "ShapeData.h"
#include <vector>

namespace PremadeShapes
{
	std::vector<Vertex> cubeVertices { 
		// Position								// Color 
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	Color(0.6f, 0.3f, 0.0f, 1.0f)), // Vertex 0
		Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	Color(0.5f, 0.0f, 0.8f, 1.0f)), // Vertex 1
		Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	Color(0.0f, 0.5f, 0.7f, 1.0f)), // Vertex 2
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	Color(0.6f, 0.3f, 0.0f, 1.0f)), // Vertex 3
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	Color(0.5f, 0.0f, 0.8f, 1.0f)), // Vertex 4
		Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	Color(0.0f, 0.5f, 0.7f, 1.0f)), // Vertex 5
		Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	Color(0.6f, 0.3f, 0.0f, 1.0f)), // Vertex 6
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	Color(0.5f, 0.0f, 0.8f, 1.0f)), // Vertex 7
	};

	std::vector<GLuint> cubeIndices {
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

	std::vector<Vertex> recVertices {
		// Position						// Color
		Vertex(glm::vec3(+0.5f, -0.5f, 0.0f),  Color(1.0f, 0.0f, 0.0f, 1.0f)), // bottom right
		Vertex(glm::vec3(+0.5f, +0.5f, 0.0f),  Color(1.0f, 0.0f, 0.0f, 1.0f)), // top right
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),  Color(1.0f, 0.0f, 1.0f, 1.0f)), // bottom left
		Vertex(glm::vec3(-0.5f, +0.5f, 0.0f),  Color(0.0f, 0.0f, 1.0f, 1.0f)), // top left
	};

	GLuint recIndices[6] = {
	0, 1, 3, // Top right tri
	1, 2, 3 // Bottom left tri
	};

	std::vector<Vertex> doubleTriangleVerticies {
		// Triangle 1
		// Position						//Color
		Vertex(glm::vec3(-1.0, +1.0, -0.5f),  Color(0.0f, 1.0f, 0.8f, 1.0f)), // Left
		Vertex(glm::vec3(0.0, -1.0, -0.5f),   Color(0.0f, 1.0f, 0.0f, 1.0f)), // Bottom
		Vertex(glm::vec3(+1.0, +1.0, -0.5f),  Color(0.0f, 1.0f, 0.4f, 1.0f)), // Right

		// Triangle 2
		// Position		    //Color
		Vertex(glm::vec3(0.0, +1.0, -0.9f),  Color(0.8f, 0.4f, 1.0f, 1.0f)), // Top
		Vertex(glm::vec3(-1.0, -1.0, +0.5f), Color(0.7f, 0.0f, 1.0f, 1.0f)), // Left
		Vertex(glm::vec3(+1.0, -1.0, +0.5f), Color(0.5f, 0.6f, 1.0f, 1.0f)), // Right
	};

	std::vector<GLuint> doubleTriangleIndicies {
		// Triangle 1
		0, 1, 2,

		// Triangle 2
		3, 4, 5
	};

	std::vector<Vertex> triangleVerticies {
		// Position						//Color
		Vertex(glm::vec3(-1.0, -1.0, +0.5f),  Color(1.0f, 0.0f, 0.6f, 1.0f)), // Left
		Vertex(glm::vec3(0.0, +1.0, +0.5f),   Color(0.1f, 0.6f, 1.0f, 1.0f)), // Top
		Vertex(glm::vec3(+1.0, -1.0, +0.5f),  Color(0.6f, 0.0f, 1.0f, 1.0f)), // Right
	};

	std::vector<GLuint> triangleIndicies {
		0, 1 ,2,
	};
};

