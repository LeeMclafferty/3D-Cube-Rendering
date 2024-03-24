#include "Object/Object3D.h"
#include <gtc/matrix_transform.hpp>

#include "StaticHelpers/ShaderHelpers.h"

Object3D::Object3D()
	:
	shapeData(ShapeData()),
	bufferManager(BufferManager()),
	scale(glm::vec3(1.0f, 1.0f, 1.0f)),
	rotation(glm::quat(0.0f, 0.0f, 0.0f, 0.0f)),
	position(glm::vec3(0.0f, 0.0f, -3.f)),
	worldForward(glm::vec3(0.f, 0.f, -1.f)),
	worldUp(glm::vec3(0.f, 1.f, 0.f)),
	worldRight(glm::vec3(1.f, 0.f, 0.f)),
	objectUpVector(glm::vec3(0.f, 1.f, 0.f)),
	objectForwardVector(glm::vec3(0.f, 0.f, -1)),
	objectRightVector(glm::vec3(1.f, 0.f, 0.f))
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
	bufferManager.CreateObjectOnGPU(
		shapeData.verticies, 
		shapeData.numVertex,
		shapeData.indices, 
		shapeData.numIndices
	);
}

glm::mat4 Object3D::GetTransformationMatrix() 
{
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
	glm::mat4 rotMatrix = glm::mat4_cast(rotation);
	glm::mat4 posMatrix = glm::translate(glm::mat4(1.0f), position);

	return posMatrix * rotMatrix * scaleMatrix;
}


void Object3D::TransformObject() 
{
	glm::mat4 transformationMatrix = GetTransformationMatrix();
	ShaderHelpers::SetUniformMatrix4(bufferManager.GetShaderProgram(), "modelTransformMatrix", transformationMatrix);
}

/*
	Pitch - rotate around x
	Yaw - rotate around y
	Roll - rotate around z
*/
void Object3D::Rotate(glm::vec2 deltas)
{
	float sensitivity = 5.f;
	float yawAngle = deltas.x * sensitivity;
	float pitchAngle = deltas.y * sensitivity;

	glm::quat yawRotation = glm::angleAxis(glm::radians(yawAngle), worldUp);
	glm::quat pitchRotation = glm::angleAxis(glm::radians(pitchAngle), worldRight);

	glm::quat currentRotation = GetRotation();
	currentRotation = yawRotation * currentRotation * pitchRotation;

	SetRotation(glm::normalize(currentRotation));

	TransformObject();
	UpdateLocalVectors();
}


void Object3D::UpdateLocalVectors() 
{
	objectForwardVector = rotation * glm::vec3(0.0, 0.0, -1.0);
	objectUpVector = rotation * glm::vec3(0.0, 1.0, 0.0);
	objectRightVector = rotation * glm::vec3(1.0, 0.0, 0.0);
}

