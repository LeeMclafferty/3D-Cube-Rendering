#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <gtc/quaternion.hpp>
#include "Object/Components/BufferManager.h"
#include "Object/TexturedObject/TexturedObject.h"
#include "Object/LightSource/LightSource.h"

class Camera;

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win, Camera* cam);
	void Draw();

	TexturedObject GetObject() const { return cubeObject; }
	TexturedObject& GetObjectRef() { return cubeObject; }

	void SetShaderProgram(GLuint programId);
	GLuint GetShaderProgram() const { return shaderProgram; }

private:

	GLFWwindow* window;
	Camera* camera;
	float GetAspectRatio();
	GLuint shaderProgram;
	TexturedObject cubeObject;
	LightSource lightSource;
	
	void SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane);
	void SetupCube();
	void SetupLightSource();

	void DrawCube();
	void DrawLightSource();

	void UpdateNormalUniform(Object3D obj);
	void SetUniforms();
	void OrbitLight(LightSource& light, const glm::vec3& centerVec, float orbitRadius, float deltaTime, float speed);
};

