#pragma once
#include <GL/glew.h>
#include <string>
#include <GLFW/glfw3.h>
#include "ObjectRenderer.h"
#include "InputHandler.h"
#include "Camera.h"

class Engine
{

public:
	Engine(struct GLFWwindow* glWin);
	void MainLoop();

private:
	struct GLFWwindow* window;
	ObjectRenderer objectRenderer;
	InputHandler inputHandler;
	Camera camera;
};

