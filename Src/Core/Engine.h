#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "ObjectRenderer.h"

class Engine
{

public:
	Engine(class GLFWwindow* glWin);
	void MainLoop();

private:
	class GLFWwindow* window;
	ObjectRenderer objectRenderer;
};

