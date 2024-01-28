#include "Engine.h"
#include <iostream>


Engine::Engine(GLFWwindow* glWin)
	:window(glWin)
{

}

void Engine::MainLoop()
{

	shaderProgram = CreateShader(vertexShader, fragmentShader);
	CreateTriangle();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Engine::CreateCube()
{

}

void Engine::Draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Engine::CreateTriangle()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO); 
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVerts), triangleVerts, GL_STATIC_DRAW);

	/*
	I enable 0 since this is specifically talking about the vertex attribute.
	In the shader source layout location to 0
	*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
}

GLuint Engine::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	// Read in Shaders .. Link them .. Compile into single shader program
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int Engine::CompileShader(unsigned int glType, const std::string& source)
{
	GLuint id = glCreateShader(glType);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int len;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
		char message[512];
		glGetShaderInfoLog(id, len, &len, message);
		
		std::cout << "Failed to compile " << (glType == GL_VERTEX_SHADER ? "vertex" : "fragment");
		std::cout << message << std::endl;
		
		glDeleteShader(id);
		return 0;
	}

	return id;
}
