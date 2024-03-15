#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <gtc/quaternion.hpp>
#include "Object/Components/BufferManager.h"
#include "Object/Object3D.h"
#include "Object/LightSource/LightSource.h"

class Camera;

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win, Camera* cam);
	void Draw();

	Object3D GetObject() const { return cubeObject; }
	Object3D& GetObjectRef() { return cubeObject; }

	void SetShaderProgram(GLuint programId);
	GLuint GetShaderProgram() const { return shaderProgram; }

private:

	GLFWwindow* window;
	Camera* camera;
	float GetAspectRatio();
	GLuint shaderProgram;
	Object3D cubeObject;
	LightSource lightSource;
	
	void SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane);
	void SetupCube();
	void SetupLightSource();
};

