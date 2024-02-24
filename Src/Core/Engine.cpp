
#include "Engine.h"
#include <iostream>

#include "StaticHelpers/ShaderHelpers.h"


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
	objectRenderer.SetupPremadeShape();
	camera.SetCameraTarget(objectRenderer.GetObjectTranslation());

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(objectRenderer.GetShaderProgram());
		objectRenderer.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteProgram(objectRenderer.GetShaderProgram());
}