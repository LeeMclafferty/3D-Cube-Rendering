#include "Camera.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/quaternion.hpp>
#include <GLFW/glfw3.h>

#include "../Time/TimeManager.h"

Camera::Camera()
	: globalPosition(glm::vec3(0.0f, 0.0f, 0.0f)),
	lookSensitivity(1.f),
	moveSensitivity(5.f),
	cameraSpeed(0.1f), 
	forwardVector(glm::vec3(0.0f, 0.0f, -1.0f)), 
	upVector(glm::vec3(0.0f, 1.0f, 0.0f)) 
{
}

glm::vec3 Camera::GetCameraForward() const
{
	return glm::normalize(forwardVector);
}

glm::vec3 Camera::GetCameraRight() const
{
	return glm::normalize(glm::cross(upVector, forwardVector));
}

glm::vec3 Camera::GetCameraUp() const
{
	return glm::normalize(upVector);
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(
		globalPosition,
		globalPosition + forwardVector,
		upVector
	);
}

void Camera::Rotate(glm::vec2 mouseDeltas) 
{
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); // Use world up for yaw to avoid roll
	glm::vec3 right = GetCameraRight();

	// Convert mouse deltas to radians and apply sensitivity
	float yawRadians = glm::radians(mouseDeltas.x * lookSensitivity);
	float pitchRadians = glm::radians(mouseDeltas.y * lookSensitivity);

	// Generate rotation matrices for yaw and pitch
	glm::mat4 yawMatrix = glm::rotate(glm::mat4(1.0f), yawRadians, up);
	glm::mat4 pitchMatrix = glm::rotate(glm::mat4(1.0f), pitchRadians, right);

	// Update local vectors
	forwardVector = glm::vec3(yawMatrix * pitchMatrix * glm::vec4(forwardVector, 0.0f));
	upVector = glm::vec3(yawMatrix * pitchMatrix * glm::vec4(upVector, 0.0f));
}

void Camera::Move(int key) 
{
	cameraSpeed = moveSensitivity * TimeManager::GetDeltaTime();
	if (key == GLFW_KEY_W) 
	{
		globalPosition += cameraSpeed * forwardVector;
	}
	else if (key == GLFW_KEY_S) 
	{
		globalPosition -= cameraSpeed * forwardVector;
	}
	else if (key == GLFW_KEY_A) 
	{
		globalPosition -= glm::normalize(glm::cross(forwardVector, upVector)) * cameraSpeed;
	}
	else if (key == GLFW_KEY_D) 
	{
		globalPosition += glm::normalize(glm::cross(forwardVector, upVector)) * cameraSpeed;
	}
	else if (key == GLFW_KEY_E)
	{
		globalPosition += cameraSpeed * upVector;
	}
	else if (key == GLFW_KEY_Q)
	{
		globalPosition -= cameraSpeed * upVector;
	}
}

void Camera::UpdateLocalVectors(glm::mat4 rotation)
{
	glm::vec4 forwardV4 = glm::vec4(forwardVector, 0.f);
	glm::vec4 upV4 = glm::vec4(upVector, 0.f);
	
	forwardV4 = rotation * forwardV4;
	upV4 = rotation * upV4;

	forwardVector = glm::vec3(forwardV4);
	upVector = glm::vec3(upV4);
}

