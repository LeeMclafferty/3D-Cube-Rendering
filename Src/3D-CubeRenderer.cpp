
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Core/Engine.h"

int main(void)
{
	int windowWidth = 1600, windowHeight = 1200;
	GLFWwindow* window;

	/* Initialize GLFW */
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(windowWidth, windowHeight, "The 3D Cube", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	/* Initialize GLEW */
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	Engine engine(window);

	engine.MainLoop();

	glfwTerminate();
	return 0;
}

