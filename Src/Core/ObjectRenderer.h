#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <gtc/quaternion.hpp>
#include "../Components/BufferManager.h"
#include "Object/Object3D.h"

class Camera;

class ObjectRenderer
{

public:
	ObjectRenderer(GLFWwindow* win, Camera* cam);
	void Draw();

	Object3D GetObject() const { return object; }
	Object3D& GetObjectRef() { return object; }

	void SetShaderProgram(GLuint programId);
	GLuint GetShaderProgram() const { return shaderProgram; }

private:

	GLFWwindow* window;
	Camera* camera;
	Object3D object;
	float GetAspectRatio();
	GLuint shaderProgram;
	
	void SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane);
};

