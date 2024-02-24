#include "InputHandler.h"
#include <iostream>
#include <cmath>
#include <glm.hpp>
#include <matrix_transform.hpp>
#include "ObjectRenderer.h"
#include "../Camera.h"

/* Static member functions cannot access non-static members. Creating static pointer to self to access members.*/
static InputHandler* instance = nullptr;

InputHandler::InputHandler(GLFWwindow* win, ObjectRenderer* objRenderer, Camera* cam)
	:window(win), objectRenderer(objRenderer), inputState(InputState::defaultInput), camera(cam)
{
	instance = this;
	BindCallbackFuncs();
	sensitivity = 0.5f;
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
	if (!instance) return;

	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.1f, 0.f));
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(-0.1f, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, -0.1f, 0.f));
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(0.1f, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.f, 0.1f));
	}
	else if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		//instance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.f, -0.1f));
	}
}

void InputHandler::ScrollCallback(GLFWwindow* win, double xoffset, double yoffset)
{
	const float scaleFactor = 0.1f;

	if (yoffset != 0)
	{
		float scaleAdjustment = (yoffset > 0) ? scaleFactor : -scaleFactor;
		//instance->objectRenderer->AddObjectScale(glm::vec3(scaleAdjustment));
		instance->objectRenderer->SetObjectScale(
			glm::max(instance->objectRenderer->GetObjectScale(), glm::vec3(0.1f))
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
		RotateMesh(xpos, ypos);
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

// TODO: Create and move to a class for manipulation meshes
void InputHandler::RotateMesh(double xpos, double ypos)
{
	SetMouseDeltas(xpos, ypos);
	UpdateLastMousePos(xpos, ypos);

	glm::vec3 up(0.f, 1.f, 0.f);
	glm::vec3 right = glm::normalize(glm::cross(up, glm::vec3(1.f, 0.f, 0.f)));

	glm::mat4 yawRotation = glm::rotate(
		glm::mat4(1.f),
		(float)-instance->deltaX * instance->sensitivity,
		up
	);
	glm::mat4 pitchRotation = glm::rotate(
		glm::mat4(1.f),
		(float)-instance->deltaY * instance->sensitivity,
		right
	);

	glm::mat4 rotator = pitchRotation * yawRotation; 

	glm::mat4 tranformationMatrix = glm::mat4(1.f);
	glm::vec3 currentScale = instance->objectRenderer->GetObjectScale();
	glm::vec3 currentTranslation = instance->objectRenderer->GetObjectTranslation();
	tranformationMatrix = glm::scale(tranformationMatrix, currentScale);
	tranformationMatrix *= rotator;
	tranformationMatrix = glm::translate(tranformationMatrix, currentTranslation);

	instance->objectRenderer->TransformObject(tranformationMatrix);
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
	instance->deltaX = static_cast<float>(xpos - instance->lastX) * instance->sensitivity;
	instance->deltaY = static_cast<float>(ypos - instance->lastY) * instance->sensitivity;
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

