
#include "InputHandler.h"
#include <iostream>
#include <cmath>
#include <glm.hpp>
#include <matrix_transform.hpp>

#include "../ObjectRenderer.h"
#include "../Camera.h"
#include "Object/Object3D.h"

/* Static member functions cannot access non-static members. Creating static pointer to self to access members.*/
static InputHandler* instance = nullptr;

InputHandler::InputHandler(GLFWwindow* win, ObjectRenderer* objRenderer, Camera* cam)
	:window(win), objectRenderer(objRenderer), inputState(InputState::defaultInput), camera(cam),
	object(&objRenderer->GetObjectRef())
{
	instance = this;
	BindCallbackFuncs();
	meshRotationSensitivity = 0.1f;
	meshTranslationSensitivity = 0.5f;
}

void InputHandler::SetInputState(InputState newState)
{
	InputState buffer = instance->inputState;
	instance->inputState = newState;
	instance->previouseState = buffer;
}

void InputHandler::BindCallbackFuncs()
{
	glfwSetKeyCallback(window, KeyPressCallback);
	glfwSetScrollCallback(window, ScrollCallback);
	glfwSetMouseButtonCallback(window, MouseCallback);
	glfwSetCursorPosCallback(window, CursorPositionCallback);
}

void InputHandler::KeyPressCallback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (instance->inputState == InputState::cameraInput)
	{
		CameraTransformKeyboardEvents(win, key, scancode, action, mods);
	}
	else
	{
		ObjectTransformKeyboardEvents(win, key, scancode, action, mods);
	}
}

void InputHandler::ScrollCallback(GLFWwindow* win, double xoffset, double yoffset)
{
	const float scaleFactor = 0.1f;

	if (yoffset != 0)
	{
		float scaleAdjustment = (yoffset > 0) ? scaleFactor : -scaleFactor;
		instance->object->AddScale(glm::vec3(scaleAdjustment));
		instance->object->SetScale(
			glm::max(
				instance->object->GetScale(), 
				glm::vec3(0.1f)
			)
		);
	}
}

void InputHandler::MouseCallback(GLFWwindow* window, int button, int action, int mod)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		OnLeftMouseButton(button, action, mod);
	}
	else if ( button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		OnRightMouseButton(button, action, mod);
	}
}

void InputHandler::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (instance->inputState == InputState::mouseInput)
	{
		SetMouseDeltas(xpos, ypos);
		instance->object->Rotate(glm::vec2(instance->deltaX, instance->deltaY));
	}
	else if (instance->inputState == InputState::cameraInput)
	{
		if(!instance->camera) return;
		SetMouseDeltas(xpos, ypos);
		instance->camera->Rotate(
			glm::vec2(instance->deltaX, instance->deltaY)
		);
	}
}

void InputHandler::SetLastMouseCoordinates()
{
	glfwGetCursorPos(instance->window, &instance->lastX, &instance->lastY);
}

void InputHandler::OnLeftMouseButton(int button, int action, int mod)
{
	if (action == GLFW_PRESS)
	{
		SetInputState(InputState::mouseInput);
		SetLastMouseCoordinates();
	}
	else if (action == GLFW_RELEASE)
	{
		SetInputState(instance->previouseState);
		ResetMouseDeltas();
		instance->object->UpdateLocalVectors();
	}
}

void InputHandler::OnRightMouseButton(int button, int action, int mod)
{
	if (action == GLFW_PRESS)
	{
		SetInputState(InputState::cameraInput);
		SetLastMouseCoordinates();
	}
	else if (action == GLFW_RELEASE)
	{
		SetInputState(instance->previouseState);
		ResetMouseDeltas();
	}
}

void InputHandler::SetMouseDeltas(double xpos, double ypos)
{
	instance->deltaX = static_cast<float>(xpos - instance->lastX) * instance->meshRotationSensitivity;
	instance->deltaY = static_cast<float>(ypos - instance->lastY) * instance->meshRotationSensitivity;
	instance->lastX = xpos;
	instance->lastY = ypos;
}

void InputHandler::UpdateLastMousePos(double x, double y)
{
	instance->lastX = x;
	instance->lastY = y;
}

void InputHandler::ResetMouseDeltas()
{
	instance->deltaX = 0.0;
	instance->deltaY = 0.0;
}

void InputHandler::ObjectTransformKeyboardEvents(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (!instance) return;

	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(0.f, instance->meshTranslationSensitivity, 0.f));
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(-instance->meshTranslationSensitivity, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(0.f, -instance->meshTranslationSensitivity, 0.f));
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(instance->meshTranslationSensitivity, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(0.f, 0.f, instance->meshTranslationSensitivity));
	}
	else if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		instance->object->MovePosition(glm::vec3(0.f, 0.f, -instance->meshTranslationSensitivity));
	}
}

void InputHandler::CameraTransformKeyboardEvents(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (!instance) return;
	instance->camera->Move(key);
}

