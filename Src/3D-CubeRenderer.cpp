
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Core/Engine.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize GLFW */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();

		return -1;
	}

	/* Make the window's context current */
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

