#include <iostream>
#include "ShapeCreator.h"
#include "PremadeShapes/PremadeShapes.h"

void ShapeCreator::CreateCube()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PremadeShapes::cubeVertices), PremadeShapes::cubeVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(PremadeShapes::cubeIndices), PremadeShapes::cubeIndices, GL_STATIC_DRAW);
	
	/*
	I enable 0 since this is specifically talking about the vertex attribute.
	In the shader source layout location to 0
	*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)0);

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(GLfloat) * 7, (char*)(sizeof(GLfloat) * 3));
}


void ShapeCreator::CreateRectangle()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PremadeShapes::recVertices), PremadeShapes::recVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(PremadeShapes::recIndices), PremadeShapes::recIndices, GL_STATIC_DRAW);
	/*
	I enable 0 since this is specifically talking about the vertex attribute.
	In the shader source layout location to 0
	*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

}

void ShapeCreator::CreateTriangle()
{
	// Generate .. Bind Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PremadeShapes::triangleVerticies), PremadeShapes::triangleVerticies, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(PremadeShapes::triangleIndicies), PremadeShapes::triangleIndicies, GL_STATIC_DRAW);

	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(GLfloat) * 7, (void*)0);

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(GLfloat) * 7, (char*)(sizeof(GLfloat) * 3));

}

void ShapeCreator::CreateDoubleTriangles()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PremadeShapes::doubleTriangleVerticies), PremadeShapes::doubleTriangleVerticies, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(PremadeShapes::doubleTriangleIndicies), PremadeShapes::doubleTriangleIndicies, GL_STATIC_DRAW);

	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(GLfloat) * 7, (void*)0);

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(GLfloat) * 7, (char*)(sizeof(GLfloat) * 3));
}
