#include "Engine.h"
#include <iostream>

#include "StaticHelpers/ShaderHelpers.h"

Engine::Engine(GLFWwindow* glWin)
	:window(glWin), objectRenderer(ObjectRenderer())
{
	glEnable(GL_DEPTH_TEST);
}

void Engine::MainLoop()
{
	ShaderHelpers::ShaderSource source = ShaderHelpers::ParseShader("Resources/Shaders/Basic.shader");
	GLuint shaderProgram = objectRenderer.CreateShader(source.vertexSource, source.fragmentSource);
	objectRenderer.SetupPremadeShape();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram);
		objectRenderer.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(shaderProgram);
}