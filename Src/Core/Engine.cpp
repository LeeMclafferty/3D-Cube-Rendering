
#include "Engine.h"
#include <iostream>

#include "StaticHelpers/ShaderHelpers.h"
#include "../Time/TimeManager.h"
#include "Texture/Texture.h"

Engine::Engine(GLFWwindow* glWin)
	:window(glWin), objectRenderer(ObjectRenderer(glWin, &camera)), 
	inputHandler(glWin, &objectRenderer, &camera)
{
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
}

void Engine::MainLoop()
{
	ShaderHelpers::ShaderSource source = ShaderHelpers::ParseShader("Resources/Shaders/Basic.shader");
	objectRenderer.SetShaderProgram(
			ShaderHelpers::CreateShader(
			source.vertexSource, 
			source.fragmentSource 
			)
	);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(objectRenderer.GetShaderProgram());
		objectRenderer.Draw();
		TimeManager::UpdateDeltatime();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(objectRenderer.GetShaderProgram());
}
