#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "PremadeShapes/ShapeCreator.h"

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win);
	void SetupPremadeShape();
	void Draw();
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int glType, const std::string& source);

	glm::vec3 GetObjectScale() { return objectScale; }
	glm::vec3 GetObjectRotation() { return objectRotation; }
	glm::vec3 GetObjectTranslation() { return objectTranslation; }

	void SetObjectScale(glm::vec3 scale) { objectScale = scale; }
	void SetObjectRotation(glm::vec3 rot) { objectRotation = rot; }

	void AddObjectScale(glm::vec3 scale);
	void AddObjectRotation(glm::vec3 rot);
	void AddObjectTranslation(glm::vec3 trans);

	void SetRotationAngle(float rot) { rotationAngle += rot; }

private:

	GLFWwindow* window;
	ShapeCreator shapeCreator;
	float GetAspectRatio();
	GLuint shaderProgram;
	
	void SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane);
	void TransformObject(glm::vec3 scale, glm::vec3 rotation, float rotationAngle, glm::vec3 translation);

	glm::vec3 objectScale;
	glm::vec3 objectRotation;
	glm::vec3 objectTranslation;

	float rotationAngle;
};

