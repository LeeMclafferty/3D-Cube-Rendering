#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ShapeData.h"

class ShapeCreator
{
public:
	void CreateCube();
	void CreateRectangle();
	void CreateTriangle();
	void CreateDoubleTriangles();

	GLuint GetVAO() { return VAO; }
	GLuint GetVBO() { return VBO; }
	GLuint GetEBO() { return EBO; }

private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	ShapeData premadeShapeData;
};

