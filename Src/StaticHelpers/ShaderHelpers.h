#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>

namespace ShaderHelpers
{
	struct ShaderSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

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
}