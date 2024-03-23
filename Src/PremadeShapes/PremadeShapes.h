#pragma once

#include <GL/glew.h>
#include "ShapeData.h"
#include <vector>

namespace PremadeShapes
{
	std::vector<Vertex> cubeVertices = {
		// Front Blue
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(0.0f, 0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), Color(0.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(0.0f, 0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), Color(0.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),

		// Right Green
		Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), Color(0.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), Color(0.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), Color(0.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), Color(0.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),

		// Back Red
		Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), Color(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), Color(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(1.0f, 0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),

		// Left Magenta
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(1.0f, 0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),

		// Top Cyan
		Vertex(glm::vec3( 0.5f, 0.5f, -0.5f),  Color(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),  Color(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, 0.5f,  0.5f),  Color(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f,  0.5f),  Color(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),

		// Bottom Yellow
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f))
	};

	std::vector<Vertex> LightSource = {
		// Front
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)),

		// Right
		Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
													 
		// Back 
		Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)),
													 
		// Left
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)),
													 
		// Top
		Vertex(glm::vec3( 0.5f, 0.5f, -0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3( 0.5f, 0.5f,  0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f,  0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
													 
		// Bottom
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f,  0.5f),  Color(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f))
	};

	std::vector<unsigned int> cubeIndices = {
		// Front face 
		1,3,0,
		3,2,0,
		// Right face 
		4,6,5,
		6,7,5,
		// Back face 
		9,11,8,
		11,10,8,
		// Left face 
		12,14,13,
		14,15,13,
		// Top face 
		18,16,19,
		16,17,19,
		// Bottom face
		21,23,20,
		23,22,20
	};

	std::vector<Vertex> recVertices {
		// Position								// Color
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
		// Position								//Color
		Vertex(glm::vec3(-1.0, -1.0, +0.5f),  Color(1.0f, 0.0f, 0.6f, 1.0f)), // Left
		Vertex(glm::vec3(0.0, +1.0, +0.5f),   Color(0.1f, 0.6f, 1.0f, 1.0f)), // Top
		Vertex(glm::vec3(+1.0, -1.0, +0.5f),  Color(0.6f, 0.0f, 1.0f, 1.0f)), // Right
	};

	std::vector<GLuint> triangleIndicies {
		0, 1 ,2,
	};
};

