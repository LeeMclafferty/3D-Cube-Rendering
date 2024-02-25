#include "Object/Object3D.h"
#include <gtc/matrix_transform.hpp>

Object3D::Object3D()
	:
	shapeData(ShapeData()),
	bufferManager(BufferManager()),
	scale(glm::vec3(1.0f, 1.0f, 1.0f)),
	rotation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f)),
	position(glm::vec3(0.0f, 0.0f, 0.0f)),
	worldForward(glm::vec3(0.f, 0.f, -1.f)),
	worldUp(glm::vec3(0.f, 1.f, 0.f)),
	worldRight(glm::vec3(1.f, 0.f, 0.f)),
	objectUpVector(glm::vec3(0.f, 1.f, 0.f)),
	objectForwardVector(0.f, 0.f, -1.f),
	objectRightVector(1.f, 0.f, 0.f)
{

}

void Object3D::SetShapeData(std::vector<Vertex> verticies, std::vector<GLuint> indicies, size_t vertexCount, size_t indexCount)
{
	shapeData.verticies = verticies;
	shapeData.indices = indicies;
	shapeData.numVertex = vertexCount;
	shapeData.numIndices = indexCount;
}

void Object3D::CreateShapeOnGPU()
{
	bufferManager.CreateObject(
		shapeData.verticies, 
		shapeData.numVertex,
		shapeData.indices, 
		shapeData.numIndices
	);
}

glm::mat4 Object3D::GetTransformationMatrix()
{
	glm::mat4 posMatrix = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotMatrix = glm::mat4_cast(rotation);
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

	return scaleMatrix * rotMatrix * posMatrix;
}

void Object3D::Rotate(float deltaX, float deltaY)
{
  	float sensitivity = 0.005f;
	float yawAngle = deltaX * sensitivity;
	float pitchAngle = deltaY * sensitivity;

	glm::quat yawRotation = glm::angleAxis(yawAngle, objectUpVector);
	glm::quat pitchRotation = glm::angleAxis(pitchAngle, objectRightVector);

	glm::quat currentRotation = GetRotation();
	currentRotation = currentRotation * pitchRotation * yawRotation;

	SetRotation(currentRotation);
	UpdateLocalVectors();
}

void Object3D::UpdateLocalVectors()
{
	objectForwardVector = rotation * glm::vec3(0.0, 0.0, -1.0);
	objectUpVector = rotation * glm::vec3(0.0, 1.0, 0.0);
	objectRightVector = rotation * glm::vec3(1.0, 0.0, 0.0);
}
