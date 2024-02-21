#pragma 
#include <glm.hpp>

class Camera
{
public:
	Camera();

	glm::vec3 GetGlobalPosition() { return globalPosition; }
	glm::vec3 GetCameraTarget() { return cameraTarget; }
	glm::vec3 GetCameraDirection() const;
	glm::vec3 GetCameraRight() const;
	glm::vec3 GetCameraUp() const;
	glm::mat4 GetViewMatrix() const;

	void SetGlobalPosition(glm::vec3 pos) { globalPosition = pos; }
	void SetCameraTarget(glm::vec3 pos) { cameraTarget = pos; }

private:

	glm::vec3 globalPosition;
	glm::vec3 cameraTarget;
};

