#include "Engine.h"


Engine::Engine(GLFWwindow* glWin)
	:window(glWin)
{

}

void Engine::MainLoop()
{
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
}
