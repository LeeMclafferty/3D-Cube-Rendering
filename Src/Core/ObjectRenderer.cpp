#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "PremadeShapes/ShapeData.h"
#include "Camera.h"


ObjectRenderer::ObjectRenderer(GLFWwindow* win, Camera* cam)
	:shapeCreator(ShapeCreator()), shaderProgram(0), window(win), camera(cam),
	objectScale(glm::vec3(1.f)), objectRotation(glm::vec3(1.f,1.f,1.f)), 
	objectTranslation(glm::vec3(0.f, 0.f, -5.f)), rotationAngle(0.f)
{
}

void ObjectRenderer::SetupPremadeShape()
{
	shapeCreator.CreateCube();
}

void ObjectRenderer::Draw() 
{
	glBindVertexArray(shapeCreator.GetVAO());
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	TransformObject(objectScale, objectRotation, rotationAngle, objectTranslation);
	SendProjectionData(60.f, GetAspectRatio(), .1f, 100.f);
	ShaderHelpers::SetUniform(shaderProgram, "viewMatrix", camera->GetViewMatrix());
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

unsigned int ObjectRenderer::CompileShader(unsigned int glType, const std::string& source)
{
	GLuint id = glCreateShader(glType);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!ShaderHelpers::CompiledSuccessfully(result, id, glType))
	{
		return 0;
	}

	return id;
}

GLuint ObjectRenderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	// Read in Shaders .. Link them .. Compile into single shader program
	shaderProgram = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);
	glValidateProgram(shaderProgram);

	int result;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	if (!ShaderHelpers::LinkedSuccessfully(result, shaderProgram))
	{
		return 0;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);

	return shaderProgram;
}

float ObjectRenderer::GetAspectRatio()
{
	if (!window) return -1.f;

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	return width / (float)height;
}

/* Setup Projection Matrix and send data to shader's uniform variable */
void ObjectRenderer::SendProjectionData(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
	ShaderHelpers::SetUniform(shaderProgram, "projectionMatrix", projectionMatrix);
}

/* Send Transformations to Vertex Shader. SRT order*/
void ObjectRenderer::TransformObject(glm::vec3 scale, glm::vec3 rotation, float rotationAngle, glm::vec3 translation)
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
	glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationAngle), rotation);
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation);
	glm::mat4 modelTransformMatrix = translationMatrix * rotationMatrix * scaleMatrix;

	ShaderHelpers::SetUniform(shaderProgram, "modelTransformMatrix", modelTransformMatrix);
}

void ObjectRenderer::AddObjectScale(glm::vec3 scale)
{
	objectScale += scale;
}

void ObjectRenderer::AddObjectRotation(glm::vec3 rot)
{
	objectRotation += rot;
}

void ObjectRenderer::AddObjectTranslation(glm::vec3 trans)
{
	objectTranslation += trans;
}

