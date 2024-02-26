#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace ShaderHelpers
{
	struct ShaderSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	/* All memebers of static class must be static */
	static ShaderSource ParseShader(const std::string& filePath)
	{

		enum class ShaderType
		{
			NONE = -1,
			VERTEX = 0,
			FRAGMENT = 1
		};

		std::fstream stream(filePath);

		std::string line;
		std::stringstream ss[2];
		ShaderType shaderType = ShaderType::NONE;

		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					shaderType = ShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{
					shaderType = ShaderType::FRAGMENT;
				}
			}
			else
			{
				// Use the enum value as the array index
				ss[(int)shaderType] << line << '\n';
			}
		}
		return { ss[0].str(), ss[1].str() };
	}

	static bool CompiledSuccessfully(int& result, const GLuint& id, const GLuint& glType)
	{
		if (result == GL_FALSE)
		{
			int len;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
			char* message = new GLchar[len];
			glGetShaderInfoLog(id, len, &len, message);

			std::cout << "Failed to compile " << (glType == GL_VERTEX_SHADER ? "vertex" : "fragment");
			std::cout << message << std::endl;

			glDeleteShader(id);
			delete[] message;
			return false;
		}
		return true;
	}

	static bool LinkedSuccessfully(int& result, const GLuint& id)
	{
		if (result == GL_FALSE)
		{
			int len;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
			char* message = new GLchar[len];
			glGetProgramInfoLog(id, len, &len, message);

			std::cout << message << std::endl;

			glDeleteShader(id);
			delete[] message;
			return false;
		}
		return true;
	}

	static void SetUniform(GLuint shader, std::string uniformName, glm::mat4 matrix)
	{
		GLint modelTransformMatrixUniform = glGetUniformLocation(shader, uniformName.c_str());
		glUniformMatrix4fv(modelTransformMatrixUniform, 1, GL_FALSE, &matrix[0][0]);
	}

	static unsigned int CompileShader(unsigned int glType, const std::string& source)
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

	static GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		// Read in Shaders .. Link them .. Compile into single shader program
		GLuint shaderProgram = glCreateProgram();
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
}