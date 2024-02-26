#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

struct Vertex;

class BufferManager
{
public:
	void CreateObject(const std::vector<Vertex> vertices, size_t vertexCount, const std::vector<GLuint> indices, size_t indexCount);

	GLuint GetVAO() { return VAO; }
	GLuint GetVBO() { return VBO; }
	GLuint GetEBO() { return EBO; }
	
	GLuint GetShaderProgram() { return shaderProgram; }
	void SetShaderProgram(GLuint program) { shaderProgram = program; }

private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	GLuint shaderProgram;
};

