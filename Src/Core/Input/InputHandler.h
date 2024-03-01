#pragma once

#include "glm.hpp"
struct GLFWwindow;
class ObjectRenderer;
class Camera;
class Object3D;

class InputHandler
{
	enum InputState
	{
		defaultInput,
		cameraInput,
		mouseInput
	};

public:
	InputHandler(GLFWwindow* win, ObjectRenderer* objRenderer, Camera* cam);

	InputState GetInputState() const { return inputState; }

	static void SetInputState(InputState newState);

private:
	GLFWwindow* window;
	ObjectRenderer* objectRenderer;
	Object3D* object;
	Camera* camera;
	InputState inputState;
	InputState previouseState;
	
	void BindCallbackFuncs();
	static void KeyPressCallback(GLFWwindow* win, int key, int scancode, int action, int mods);
	static void ScrollCallback(GLFWwindow* win, double xoffset, double yoffset);
	static void MouseCallback(GLFWwindow* window, int button, int action, int mod);
	static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

	double lastX, lastY, deltaX, deltaY = 0.0;
	float meshRotationSensitivity;
	float meshTranslationSensitivity;

	static void SetLastMouseCoordinates();
	static void OnLeftMouseButton(int button, int action, int mod);
	static void OnRightMouseButton(int button, int action, int mod);

	static void SetMouseDeltas(double xpos, double ypos);
	static void UpdateLastMousePos(double x, double y);
	static void ResetMouseDeltas();

	static void ObjectTransformKeyboardEvents(GLFWwindow* win, int key, int scancode, int action, int mods);
	static void CameraTransformKeyboardEvents(GLFWwindow* win, int key, int scancode, int action, int mods);
};

