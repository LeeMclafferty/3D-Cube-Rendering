
#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "PremadeShapes/PremadeShapes.h"
#include "Camera.h"

ObjectRenderer::ObjectRenderer(GLFWwindow* win, Camera* cam)
	:shaderProgram(0), window(win), camera(cam), 
	cubeObject("D:\\Dev\\LocalRepos\\3D-CubeRenderer\\Resources\\Textures\\T_WorldGrid.png")
{
}

void ObjectRenderer::Draw() 
{
	DrawLightSource();
	DrawCube();
}

void ObjectRenderer::SetShaderProgram(GLuint programId)
{
	cubeObject.SetShaderProgram(programId);
	lightSource.SetShaderProgram(programId);
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
	ShaderHelpers::SetUniformMatrix4(shaderProgram, "projectionMatrix", projectionMatrix);
}

void ObjectRenderer::SetupCube()
{
	size_t vertexCount = PremadeShapes::cubeVertices.size();
	size_t indexCount = PremadeShapes::cubeIndices.size();
	cubeObject.SetShapeData(
		PremadeShapes::cubeVertices, PremadeShapes::cubeIndices,
		vertexCount, indexCount
	);
	cubeObject.CreateShapeOnGPU();
	cubeObject.SetShaderProgram(shaderProgram);
}

void ObjectRenderer::SetupLightSource()
{
	size_t vertexCount = PremadeShapes::LightSource.size();
	size_t indexCount = PremadeShapes::cubeIndices.size();
	lightSource.SetShapeData(
		PremadeShapes::LightSource, PremadeShapes::cubeIndices,
		vertexCount, indexCount
	);
	lightSource.CreateShapeOnGPU();
	lightSource.SetShaderProgram(shaderProgram);

	lightSource.SetPosition(glm::vec3(2.0f, 0.0f, 0.0f));
}

void ObjectRenderer::DrawCube()
{
	ShaderHelpers::ShaderSource source = ShaderHelpers::ParseShader("Resources/Shaders/Basic.shader");
	SetShaderProgram(
		ShaderHelpers::CreateShader(
			source.vertexSource,
			source.fragmentSource
		)
	);
	glUseProgram(GetShaderProgram());

	SetupCube();
	SendProjectionData(60.f, GetAspectRatio(), .01f, 1000.f);
	ShaderHelpers::SetUniformMatrix4(shaderProgram, "viewMatrix", camera->GetViewMatrix());
	ShaderHelpers::SetUniformVec4(shaderProgram, "lightingColor", lightSource.GetColor());
	ShaderHelpers::SetUniformSampler2D(shaderProgram, "textureImg");
	ShaderHelpers::SetUniformVec3(shaderProgram, "lightPos", lightSource.GetPosition());

	UpdateNormalUniform(cubeObject);

	glBindVertexArray(cubeObject.GetVAO());
	cubeObject.TransformObject();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void ObjectRenderer::DrawLightSource()
{
	ShaderHelpers::ShaderSource source = ShaderHelpers::ParseShader("Resources/Shaders/LightSource.shader");
	SetShaderProgram(
		ShaderHelpers::CreateShader(
			source.vertexSource,
			source.fragmentSource
		)
	);
	glUseProgram(GetShaderProgram());

	SetupLightSource();
	SendProjectionData(60.f, GetAspectRatio(), .01f, 1000.f);
	ShaderHelpers::SetUniformMatrix4(shaderProgram, "viewMatrix", camera->GetViewMatrix());

	glBindVertexArray(lightSource.GetVAO());
	lightSource.TransformObject();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void ObjectRenderer::UpdateNormalUniform(Object3D obj)
{
	// Update normal as view changes.
	glm::mat4 modelMatrix = obj.getlo();
	glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(modelMatrix)));
	ShaderHelpers::SetUniformMatrix3(GetShaderProgram(), "normalMatrix", normalMatrix);
}
