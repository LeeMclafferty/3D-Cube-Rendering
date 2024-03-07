
#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "PremadeShapes/PremadeShapes.h"
#include "Camera.h"

ObjectRenderer::ObjectRenderer(GLFWwindow* win, Camera* cam)
	:shaderProgram(0), window(win), camera(cam)
{
	size_t vertexCount = PremadeShapes::cubeVertices.size();
	size_t indexCount = PremadeShapes::cubeIndices.size();
	object.SetShapeData(
		PremadeShapes::cubeVertices, PremadeShapes::cubeIndices, 
		vertexCount, indexCount
	);
	object.CreateShapeOnGPU();
	object.SetShaderProgram(shaderProgram);
}

void ObjectRenderer::Draw() 
{
	glBindVertexArray(object.GetVAO());
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	object.TransformObject();

	SendProjectionData(60.f, GetAspectRatio(), .01f, 1000.f);
	ShaderHelpers::SetUniformMatrix(shaderProgram, "viewMatrix", camera->GetViewMatrix());
	GLint textureUniformLocation = glGetUniformLocation(shaderProgram, "textureImg");
	glUniform1i(textureUniformLocation, 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void ObjectRenderer::SetShaderProgram(GLuint programId)
{
	object.SetShaderProgram(programId);
	shaderProgram = programId;
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
	ShaderHelpers::SetUniformMatrix(shaderProgram, "projectionMatrix", projectionMatrix);
}
