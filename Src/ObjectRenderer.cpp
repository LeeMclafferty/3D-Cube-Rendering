#include "ObjectRenderer.h"
#include <iostream>
#include "StaticHelpers/ShaderHelpers.h"

void ObjectRenderer::Draw() 
{
	glBindVertexArray(VAO);
	//glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
}

void ObjectRenderer::CreateCube()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

	/*
	I enable 0 since this is specifically talking about the vertex attribute.
	In the shader source layout location to 0
	*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);
}


void ObjectRenderer::CreateRectangle()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(recVertices), recVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(recIndices), recIndices, GL_STATIC_DRAW);
	/*
	I enable 0 since this is specifically talking about the vertex attribute.
	In the shader source layout location to 0
	*/
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)0);

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLuint) * 7, (char*)(sizeof(GLfloat) * 3));
}

void ObjectRenderer::CreateDoubleTriangles()
{
	// Generate .. Bind .. Copy
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(doubleTriangleVerticies), doubleTriangleVerticies, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(doubleTriangleIndicies), doubleTriangleIndicies, GL_STATIC_DRAW);

	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(GLfloat) * 7, (char*)(sizeof(GLfloat) * 3));

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(GLfloat) * 7, (char*)(sizeof(GLfloat) * 3));
}

GLuint ObjectRenderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	// Read in Shaders .. Link them .. Compile into single shader program
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	int result;
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!ShaderHelpers::LinkedSuccessfully(result, program))
	{
		return 0;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
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
