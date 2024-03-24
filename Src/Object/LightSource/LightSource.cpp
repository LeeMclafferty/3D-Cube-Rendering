#include "LightSource.h"

LightSource::LightSource()
	:color(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f))
{

}

void LightSource::CreateShapeOnGPU()
{
	bufferManager.CreateLightSourceOnGPU(
		shapeData.verticies,
		shapeData.numVertex,
		shapeData.indices,
		shapeData.numIndices
	);
}
