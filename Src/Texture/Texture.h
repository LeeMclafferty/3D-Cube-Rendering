#pragma once
class Texture
{
public:
	Texture();

private:
	int width, height, nrChannels;
	unsigned char* tData;

	void GenTexture(const char* path);

	unsigned int bufferId;
};

