#pragma once

#include "glm.hpp"
struct GLFWwindow;
class ObjectRenderer;

class InputHandler
{
	// Not indexing at 0 to match keyboard inputs
	enum InputState
	{
		scaling = 1,
		rotating = 2,
		translating = 3,
		camera = 4,
		mouse = 5
	};

public:
	InputHandler(GLFWwindow* win, ObjectRenderer* objRenderer);

private:
	GLFWwindow* window;
	ObjectRenderer* objectRenderer;
	InputState inputState;
	InputState previouseState;
	
	void BindCallbackFuncs();
	static void KeyPressCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
	static void ScrollCallback(GLFWwindow* win, double xoffset, double yoffset);
	static void MouseCallback(GLFWwindow* window, int button, int action, int mod);
	static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

	double lastX, lastY, deltaX, deltaY = 0.0;
};

