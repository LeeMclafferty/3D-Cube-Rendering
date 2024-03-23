#include "Object/TexturedObject/TexturedObject.h"

TexturedObject::TexturedObject()
	:texture(Texture())
{

}

TexturedObject::TexturedObject(const char* tPath)
	:texture(Texture(tPath))
{

}

void TexturedObject::SetTexture(Texture tex)
{
	texture = tex;
}
