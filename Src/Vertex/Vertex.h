#pragma once
#include "glm.hpp"

/*
	glm has a vec4, but I want to keep things clear with an RGBA value. 
*/
struct Color
{
	Color()
		:r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}

	Color(float rIn, float gIn, float bIn, float aIn)
		:r(rIn), g(gIn), b(bIn), a(aIn) {}

	float r, g, b, a;
};

struct Vertex
{
	Vertex(glm::vec3 pos, Color col)
		: position(pos), color(col), textureCoordinates(glm::vec3(0.f, 0.f, 0.f)), normals(glm::vec3(0.f, 0.f, 0.f))
	{}

	Vertex(glm::vec3 pos, Color col, glm::vec2 coords, glm::vec3 n)
		: position(pos), color(col), textureCoordinates(coords), normals(n)
	{}

	glm::vec3 position;
	Color color;
	glm::vec2 textureCoordinates;
	glm::vec3 normals;
};

