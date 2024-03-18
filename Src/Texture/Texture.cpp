#include "Texture.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "stb_image/stb_image.h"

Texture::Texture()
 :width(0), height(0), nrChannels(3), tData(nullptr), bufferId(NULL)
{
	GenTexture("D:\\Dev\\LocalRepos\\3D-CubeRenderer\\Resources\\Textures\\T_WorldGrid.png");
}

Texture::Texture(const char* path)
 :width(0), height(0), nrChannels(3), tData(nullptr), bufferId(NULL)
{
	GenTexture(path);
}

void Texture::GenTexture(const char* path)
{
	glActiveTexture(GL_TEXTURE0); // Zero is activated by default so not 100% needed in this use case.
	glGenTextures(1, &bufferId);
	glBindTexture(GL_TEXTURE_2D, bufferId);

	// Set texture wrapping and filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	tData = stbi_load(path, &width, &height, &nrChannels, 0);
	if (tData)
	{
		GLenum format = GL_RED;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

		// have to set GL_UNPACK_ALIGNMENT to 1 since the images only have 3 color channels. 
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, tData);
		glGenerateMipmap(GL_TEXTURE_2D);

		std::cout << "Succeeded to load texture: " << path << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture: " << path << std::endl;
	}

	stbi_image_free(tData);
}

