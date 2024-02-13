#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Struct/Vertex.h"
struct Vertex;

struct ShapeData
{
	Vertex* verticies;
	GLuint* indices;
};