#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "PremadeShapes/ShapeCreator.h"

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win);
	void SetupPremadeShape();
	void Draw();
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int glType, const std::string& source);

private:

	GLFWwindow* window;
	ShapeCreator shapeCreator;
	float GetAspectRatio();
	GLuint shaderProgram;
};

