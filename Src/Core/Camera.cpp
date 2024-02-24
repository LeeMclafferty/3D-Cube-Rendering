#include "Camera.h"
#include <glm.hpp>
#include <matrix_transform.hpp>

Camera::Camera()
	:globalPosition(glm::vec3(0.f, 0.f, 0.f)), cameraTarget(0.f, 0.f, -3.f), sensitivity(.003f)
{
}

glm::vec3 Camera::GetCameraDirection() const
{
	return globalPosition + cameraTarget;
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
		globalPosition,
		GetCameraDirection(),
		GetCameraUp()
	);
}

void Camera::Rotate(glm::vec2 mouseDeltas)
{
	glm::vec3 up = GetCameraUp(); 
	glm::vec3 right = GetCameraRight();

	glm::mat4 yawRotation = glm::rotate(glm::mat4(1.0f), mouseDeltas.x * sensitivity, up);
	glm::mat4 pitchRotation = glm::rotate(glm::mat4(1.0f), -mouseDeltas.y * sensitivity, right);

	glm::mat4 rotator = pitchRotation * yawRotation;
	cameraTarget = glm::normalize(glm::mat3(rotator) * cameraTarget);
}

