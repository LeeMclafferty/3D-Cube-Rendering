#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "ObjectRenderer.h"

class Engine
{

public:
	Engine(struct GLFWwindow* glWin);
	void MainLoop();

private:
	struct GLFWwindow* window;
	ObjectRenderer objectRenderer;
};

