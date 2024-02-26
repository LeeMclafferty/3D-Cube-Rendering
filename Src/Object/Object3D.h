#pragma once

#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <vector>
#include "../Components/BufferManager.h"
#include "PremadeShapes/ShapeData.h"

struct Vertex;

class Object3D
{
public:
	Object3D();
	glm::mat4 GetTransformationMatrix();


	glm::vec3 GetScale() { return scale; }
	glm::quat GetRotation() { return rotation; }
	glm::vec3 GetPosition() { return position; }

	void SetScale(const glm::vec3& inScale) { scale = inScale; }
	void SetRotation(const glm::quat& inRotation) { rotation = inRotation; }
	void SetTranslation(const glm::vec3& translation) { position = translation; }

	void AddScale(glm::vec3 inScale) { scale += inScale; }
	void MovePosition(glm::vec3 translation) { position += translation; }

	void TransformObject(const glm::mat4& transformationMatrix);

	void Rotate(float deltaX, float deltaY);

	glm::quat GetRotation() const { return rotation; }

	void SetShapeData(std::vector<Vertex> verticies, std::vector<GLuint> indicies, size_t vertexCount, size_t indexCount);
	void CreateShapeOnGPU();

	GLuint GetVAO() { return bufferManager.GetVAO(); }
	GLuint GetVBO() { return bufferManager.GetVBO(); }
	GLuint GetEBO() { return bufferManager.GetEBO(); }

	GLuint GetShaderProgram() { return bufferManager.GetShaderProgram(); }
	void SetShaderProgram(GLuint program) { bufferManager.SetShaderProgram(program); }


private:
	
	ShapeData shapeData;
	BufferManager bufferManager;

	// World Space
	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 position; 
	glm::vec3 worldUp;
	glm::vec3 worldForward;
	glm::vec3 worldRight;

	// Local Space
	glm::vec3 objectUpVector;
	glm::vec3 objectForwardVector;
	glm::vec3 objectRightVector;

	void UpdateLocalVectors();
};

