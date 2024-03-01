#pragma 
#include <glm.hpp>

class Camera
{
public:
	Camera();

	glm::vec3 GetGlobalPosition() { return globalPosition; }
	glm::vec3 GetCameraForward() const;
	glm::vec3 GetCameraRight() const;
	glm::vec3 GetCameraUp() const;
	glm::mat4 GetViewMatrix() const;

	void SetGlobalPosition(glm::vec3 pos) { globalPosition = pos; }

	void Rotate(glm::vec2 mouseDeltas);

	void Move(int key);

private:

	glm::vec3 globalPosition;
	float lookSensitivity;
	float moveSensitivity;
	float cameraSpeed;

	glm::vec3 forwardVector;
	glm::vec3 upVector;
	void UpdateLocalVectors(glm::mat4 rotation);
};

