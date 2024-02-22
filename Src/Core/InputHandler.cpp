#include "InputHandler.h"
#include <iostream>
#include <cmath>
#include "ObjectRenderer.h"

/* Static member functions cannot access non-static members. Creating static pointer to self to access members.*/
static InputHandler* currentInstance = nullptr;

InputHandler::InputHandler(GLFWwindow* win, ObjectRenderer* objRenderer)
	:window(win), objectRenderer(objRenderer), inputState(InputState::camera)
{
	currentInstance = this;
	BindCallbackFuncs();
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
	if (!currentInstance) return;

	// State selection should be moved to ui in the future
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		currentInstance->inputState = InputState::scaling;
		std::cout << "Scaling" << std::endl;
	}
	else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		currentInstance->inputState = InputState::rotating;
		std::cout << "Rotating" << std::endl;
	}
	else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		currentInstance->inputState = InputState::translating;
		std::cout << "Translating" << std::endl;
	}
	else if (key == GLFW_KEY_4 && action == GLFW_PRESS)
	{
		currentInstance->inputState = InputState::camera;
		std::cout << "Camera" << std::endl;
	}
	else if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.1f, 0.f));
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(-0.1f, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, -0.1f, 0.f));
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(0.1f, 0.f, 0.f));
	}
	else if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.f, 0.1f));
	}
	else if (key == GLFW_KEY_X && action == GLFW_PRESS)
	{
		currentInstance->objectRenderer->AddObjectTranslation(glm::vec3(0.f, 0.f, -0.1f));
	}
}

void InputHandler::ScrollCallback(GLFWwindow* win, double xoffset, double yoffset)
{
	const float scaleFactor = 0.1f;

	if (yoffset != 0)
	{
		float scaleAdjustment = (yoffset > 0) ? scaleFactor : -scaleFactor;
		currentInstance->objectRenderer->AddObjectScale(glm::vec3(scaleAdjustment));
		currentInstance->objectRenderer->SetObjectScale(
			glm::max(currentInstance->objectRenderer->GetObjectScale(), glm::vec3(0.1f))
		);
	}
}

void InputHandler::MouseCallback(GLFWwindow* window, int button, int action, int mod)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			currentInstance->previouseState = currentInstance->inputState;
			currentInstance->inputState = InputState::mouse;
			glfwGetCursorPos(currentInstance->window, &currentInstance->lastX, &currentInstance->lastY);
		}
		else if (action == GLFW_RELEASE)
		{
			InputState buffer = currentInstance->previouseState;
			currentInstance->previouseState = InputState::mouse;
			currentInstance->inputState = buffer;

			currentInstance->deltaX = 0.0;
			currentInstance->deltaY = 0.0;
		}
	}
}

/* Rotate mesh on x and y based on mouse. */
void InputHandler::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (currentInstance->inputState == InputState::mouse)
	{
		float sensitivity = 0.05f;

		// Calculate the change in mouse position
		currentInstance->deltaX = static_cast<float>(xpos - currentInstance->lastX) * sensitivity;
		currentInstance->deltaY = static_cast<float>(ypos - currentInstance->lastY) * sensitivity;

		// Update last mouse position for the next frame
		currentInstance->lastX = xpos;
		currentInstance->lastY = ypos;

		if (currentInstance->deltaY > .1 || currentInstance->deltaY < -0.1)
		{
			float rotationAngle = std::atan2(currentInstance->deltaY, currentInstance->deltaX);
			currentInstance->objectRenderer->SetRotationAngle(rotationAngle);
			currentInstance->objectRenderer->SetObjectRotation(glm::vec3(1.0f, 0.0f, 0.0f));
		}
		else if (currentInstance->deltaX > .1 || currentInstance->deltaX < -0.1)
		{
			float rotationAngle = std::atan2(currentInstance->deltaX, currentInstance->deltaY);
			currentInstance->objectRenderer->SetRotationAngle(rotationAngle);
			currentInstance->objectRenderer->SetObjectRotation(glm::vec3(0.0f, 1.0f, 0.0f));
		}
	}

}

