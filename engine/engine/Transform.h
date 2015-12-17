#pragma once
#include <string>
#include "Vectors.h"

class Transform {
public:
	Transform();
	~Transform();

	Vector3 position;
	Vector3 scale;
	Vector4 rotation;

	// setters
	void setPosition(float x, float y, float z);
	void setScale(float x, float y, float z);
	void setRotation(float angle, float x, float y, float z);
};
