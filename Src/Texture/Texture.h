#pragma once
class Texture
{
public:
	Texture();
	Texture(const char* path);
	void GenTexture(const char* path);

private:
	int width, height, nrChannels;
	unsigned char* tData;


	unsigned int bufferId;
};

