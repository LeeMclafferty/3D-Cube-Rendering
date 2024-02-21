#include "Camera.h"
#include <matrix_transform.hpp>

Camera::Camera()
	:globalPosition(glm::vec3(0.f, 0.f, 5.f)), cameraTarget(0.f, 0.f, 0.f)
{
	GetViewMatrix();
}

glm::vec3 Camera::GetCameraDirection() const
{
	return glm::normalize(globalPosition - cameraTarget);
}

glm::vec3 Camera::GetCameraRight() const
{
	glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
	return glm::normalize(glm::cross(up, GetCameraDirection()));
}

glm::vec3 Camera::GetCameraUp() const
{
	return glm::cross(GetCameraDirection(), GetCameraRight());
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
}
