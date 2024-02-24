
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
	objectScale(glm::vec3(1.f)), objectRotation(glm::mat4(1.f)), 
	objectTranslation(glm::vec3(0.f, 0.f, -1.f))
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

	glm::mat4 tranformationMatrix = glm::mat4(1.f);
	tranformationMatrix = glm::scale(tranformationMatrix, objectScale);
	tranformationMatrix *= objectRotation;
	tranformationMatrix = glm::translate(tranformationMatrix, objectTranslation);
	TransformObject(tranformationMatrix);

	SendProjectionData(60.f, GetAspectRatio(), .01, 1000.f);
	ShaderHelpers::SetUniform(shaderProgram, "viewMatrix", camera->GetViewMatrix());
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
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

void ObjectRenderer::TransformObject(const glm::mat4& transformationMatrix)
{
	glm::mat4 currentTransform = glm::mat4(1.f);
	currentTransform = glm::scale(currentTransform, GetObjectScale());
	//currentTransform *= GetObjectRotation();
	currentTransform = glm::translate(currentTransform, GetObjectTranslation());

	currentTransform *= transformationMatrix;

	ShaderHelpers::SetUniform(shaderProgram, "modelTransformMatrix", currentTransform);
}

