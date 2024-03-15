#include "LightSource.h"

LightSource::LightSource()
{

}

void LightSource::CreateShapeOnGPU()
{
	bufferManager.CreateLightSource(
		shapeData.verticies,
		shapeData.numVertex,
		shapeData.indices,
		shapeData.numIndices
	);
}
