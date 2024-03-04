#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vertex/Vertex.h"
struct Vertex;

struct ShapeData
{
	std::vector<Vertex> verticies;
	std::vector<GLuint> indices;
	size_t numVertex;
	size_t numIndices;
};