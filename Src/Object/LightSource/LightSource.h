#pragma once
#include "Object/Object3D.h"
class LightSource : public Object3D
{
public:
	LightSource();
	virtual void CreateShapeOnGPU() override;
};

