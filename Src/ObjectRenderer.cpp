#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "PremadeShapes/ShapeData.h"


ObjectRenderer::ObjectRenderer()
	:shapeCreator(ShapeCreator()), shaderProgram(0)
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
	
	/* 
		* Create a transform matrix and projection matrix
		* Transform Matrix moves object -3 in the z axis to move away from the camera
	*/
	glm::mat4 modelTransformMatrix = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projectionMatrix = glm::perspective(60.f, 800.f / 600.f, 0.1f, 10.0f);
	
	// Send Matrix data to OpenGL using Uniform variables in the Shader.
	GLint modelTranformMatrixUniform =
		glGetUniformLocation(shaderProgram, "modelTransformMatrix");
	GLint projectionMatrixUniform =
		glGetUniformLocation(shaderProgram, "projectionMatrix");

	glUniformMatrix4fv(modelTranformMatrixUniform, 1, GL_FALSE, &modelTransformMatrix[0][0]);
	glUniformMatrix4fv(projectionMatrixUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

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

int ObjectRenderer::GetWindowWidth() const
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return mode->width;
}

int ObjectRenderer::GetWindowHeight() const
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	return mode->height;
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
