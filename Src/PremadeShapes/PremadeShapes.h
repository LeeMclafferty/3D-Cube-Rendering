#pragma once

#include <GL/glew.h>
#include "ShapeData.h"
#include <vector>

namespace PremadeShapes
{
	std::vector<Vertex> cubeVertices = {
		// Front face
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Right face
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f,  0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Back face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Left face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Top face
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Bottom face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f))

	};

	std::vector<Vertex> LightSource = {
		// Front face
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f,  0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Right face
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Back face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.5f, -0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Left face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f,  0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Top face
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),	  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),  Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f)),

		// Bottom face
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), Color(0.471f, 0.318f, 0.663f, 1.0f), glm::vec2(0.0f, 1.0f))

	};

	std::vector<unsigned int> cubeIndices = {
		// Front face
		0, 1, 2, 2, 3, 0,
		// Right face
		4, 5, 6, 6, 7, 4,
		// Back face
		8, 9, 10, 10, 11, 8,
		// Left face
		12, 13, 14, 14, 15, 12,
		// Top face
		16, 17, 18, 18, 19, 16,
		// Bottom face
		20, 21, 22, 22, 23, 20
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

