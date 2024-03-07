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
	glm::vec3 position;
	Color color;
	glm::vec2 textureCoordinates;
	Vertex(glm::vec3 pos, Color col) : position(pos), color(col) {}
	Vertex(glm::vec3 pos, Color col, glm::vec2 coords) : position(pos), color(col),
		textureCoordinates(coords) {}
};