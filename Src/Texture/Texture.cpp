#include "Texture.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "stb_image/stb_image.h"

Texture::Texture()
 :width(0), height(0), nrChannels(GL_RGBA), tData(nullptr), bufferId(NULL)
{
	GenTexture("D:\\Dev\\LocalRepos\\3D-CubeRenderer\\Resources\\Textures\\T_Stone.png");
}

void Texture::GenTexture(const char* path)
{
	glGenTextures(1, &bufferId);
	glBindTexture(GL_TEXTURE_2D, bufferId);

	/* 
	* S & T are the texture equivalent of X & Y in 2D space.
	* Mip maps is for changing texture resolution with distance
	*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	tData = stbi_load(path, &width, &height, &nrChannels, 0);

	// Send Data to GPU
	if (tData)
	{
		glTexImage2D(
			GL_TEXTURE_2D, 0, nrChannels, width, height, 
			0, nrChannels, GL_UNSIGNED_BYTE, tData
		);
		std::cout << "Succeeded to load texture" << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(tData);
}
