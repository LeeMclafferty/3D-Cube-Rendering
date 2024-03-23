#pragma once
#include "Object/Object3D.h"
#include "Texture/Texture.h"

class TexturedObject : public Object3D
{
public:
    TexturedObject();
    TexturedObject(const char* tPath);

    void SetTexture(Texture tex);
    Texture GetTexture() { return texture; }
private:
    Texture texture;
};

