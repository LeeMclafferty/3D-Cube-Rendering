#include "TimeManager.h"
#include <GLFW/glfw3.h>

float TimeManager::deltaTime = 0.f;
float TimeManager::lastFrame = 0.f;

float TimeManager::GetDeltaTime()
{
	return deltaTime;
}

void TimeManager::UpdateDeltatime()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

