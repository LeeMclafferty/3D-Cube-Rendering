#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <gtc/quaternion.hpp>
#include "PremadeShapes/ShapeCreator.h"

class Camera;

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win, Camera* cam);
	void SetupPremadeShape();
	void Draw();

	void SetShaderProgram(GLuint programId) { shaderProgram = programId; }

	glm::vec3 GetObjectScale() { return objectScale; }
	glm::mat4 GetObjectRotation() { return objectRotation; }
	glm::vec3 GetObjectTranslation() { return objectTranslation; }

	void SetObjectScale(glm::vec3 scale) { objectScale = scale; }
	void SetObjectRotation(glm::mat4 rotation) { objectRotation = rotation; }
	void SetObjectTranslation(glm::vec3 translation) { objectTranslation = translation; }

	void AddObjectScale(glm::vec3 scale) { objectScale += scale; }
	void AddObjectTranslation(glm::vec3 translation) { objectTranslation += translation; }
	
	void TransformObject(const glm::mat4& transformationMatrix);

	GLuint GetShaderProgram() const { return shaderProgram; }

private:

	GLFWwindow* window;
	Camera* camera;
	ShapeCreator shapeCreator;
	float GetAspectRatio();
	GLuint shaderProgram;
	
	void SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane);

	glm::vec3 objectScale;
	glm::mat4 objectRotation;
	glm::vec3 objectTranslation;
};

