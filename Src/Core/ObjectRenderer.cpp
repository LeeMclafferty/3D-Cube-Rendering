
#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "PremadeShapes/PremadeShapes.h"
#include "Camera.h"
#include "Time/TimeManager.h"

ObjectRenderer::ObjectRenderer(GLFWwindow* win, Camera* cam)
	:shaderProgram(0), window(win), camera(cam), 
	cubeObject("D:\\Dev\\LocalRepos\\3D-CubeRenderer\\Resources\\Textures\\T_WorldGrid.png")
{

}

void ObjectRenderer::Draw() 
{
	OrbitLight(lightSource, cubeObject.GetPosition(), 1.f, TimeManager::GetDeltaTime(), 2.f);
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

	//lightSource.SetPosition(glm::vec3(0.0f, 1.0f, -3.0f));
	lightSource.SetScale(glm::vec3(0.2f, 0.2f, 0.2f));
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

	SetUniforms();

	SetupCube();
	SendProjectionData(60.f, GetAspectRatio(), .01f, 1000.f);

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
	glm::mat4 modelMatrix = obj.GetTransformationMatrix();
	glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(modelMatrix)));
	ShaderHelpers::SetUniformMatrix3(GetShaderProgram(), "normalMatrix", normalMatrix);
}

void ObjectRenderer::SetUniforms()
{
	ShaderHelpers::SetUniformMatrix4(shaderProgram, "viewMatrix", camera->GetViewMatrix());
	ShaderHelpers::SetUniformVec4(shaderProgram, "lightingColor", lightSource.GetColor());
	ShaderHelpers::SetUniformSampler2D(shaderProgram, "textureImg");
	ShaderHelpers::SetUniformVec3(shaderProgram, "lightPos", lightSource.GetPosition());
	ShaderHelpers::SetUniformVec3(shaderProgram, "cameraPos", camera->GetGlobalPosition());
}

void ObjectRenderer::OrbitLight(LightSource& light, const glm::vec3& centerVec, float orbitRadius, float deltaTime, float speed) {
	static float angle = 0.0f;
	glm::vec3 orbitingVec(0.f,0.f,0.f);
	angle += speed * deltaTime;

	// Ensure the angle stays within the range of 0 to 2*pi
	if (angle > glm::two_pi<float>()) 
	{
		angle -= glm::two_pi<float>();
	}

	// Calculate the new position for the orbiting vector
	orbitingVec.x = centerVec.x + orbitRadius * cos(angle);
	//orbitingVec.y = centerVec.y + orbitRadius * sin(angle);
	orbitingVec.z = centerVec.z + orbitRadius * sin(angle);

	light.SetPosition(orbitingVec);
}