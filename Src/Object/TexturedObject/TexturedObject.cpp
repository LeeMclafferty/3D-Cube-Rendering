#include "Object/TexturedObject/TexturedObject.h"

TexturedObject::TexturedObject()
	:texture(Texture())
{

}

void TexturedObject::SetTexture(Texture tex)
{
	texture = tex;
}
