#pragma once
#include <string>
#include "Vectors.h"

class BoundingBox {
public:
	BoundingBox();
	~BoundingBox();

	// setters
	void setPosition(float x, float y, float z);
	void setBoundingBoxSize(float sizeX, float sizeY, float sizeZ);

	// getters
	Vector3 getBoundingBoxMin();
	Vector3 getBoundingBoxMax();

	bool checkRayIntersection(Vector3 ray_origin, Vector3 ray_direction);

private:
	Vector3 boundingBoxSize;
	Vector3 boundingBoxMin;
	Vector3 boundingBoxMax;
};
