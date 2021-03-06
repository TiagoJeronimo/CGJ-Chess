#pragma once
#include "BoundingBox.h"

BoundingBox::BoundingBox() {
	boundingBoxSize = Vector3(0.0f, 0.0f, 0.0f);
	boundingBoxMin = Vector3(0.0f, 0.0f, 0.0f);
	boundingBoxMax = Vector3(0.0f, 0.0f, 0.0f);
}

BoundingBox::~BoundingBox() {}

// setters
void BoundingBox::setPosition(float x, float y, float z) {
	boundingBoxMin = Vector3(x - boundingBoxSize.x, y, z - boundingBoxSize.z);
	boundingBoxMax = Vector3(x + boundingBoxSize.x, y + boundingBoxSize.y, z + boundingBoxSize.z);
}

void BoundingBox::setBoundingBoxSize(float sizeX, float sizeY, float sizeZ) {
	boundingBoxSize = Vector3(sizeX, sizeY, sizeZ);
}

// getters
Vector3 BoundingBox::getBoundingBoxMin() {
	return boundingBoxMin;
}

Vector3 BoundingBox::getBoundingBoxMax() {
	return boundingBoxMax;
}

bool BoundingBox::checkRayIntersection(Vector3 ray_origin, Vector3 ray_direction) {
	if (boundingBoxSize == Vector3(0.0f, 0.0f, 0.0f)) return false;

	float tmin, tmax, tymin, tymax, tzmin, tzmax, divx, divy, divz;

	divx = 1 / ray_direction.x;
	if (divx >= 0) {
		tmin = (boundingBoxMin.x - ray_origin.x) * divx;
		tmax = (boundingBoxMax.x - ray_origin.x) * divx;
	}
	else {
		tmin = (boundingBoxMax.x - ray_origin.x) * divx;
		tmax = (boundingBoxMin.x - ray_origin.x) * divx;
	}

	divy = 1 / ray_direction.y;
	if (divy >= 0) {
		tymin = (boundingBoxMin.y - ray_origin.y) * divy;
		tymax = (boundingBoxMax.y - ray_origin.y) * divy;
	}
	else {
		tymin = (boundingBoxMax.y - ray_origin.y) * divy;
		tymax = (boundingBoxMin.y - ray_origin.y) * divy;
	}
	if ((tmin > tymax) || (tymin > tmax)) 
		return false; // Intersection not detected

	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;

	divz = 1 / ray_direction.z;
	if (divz >= 0) {
		tzmin = (boundingBoxMin.z - ray_origin.z) * divz;
		tzmax = (boundingBoxMax.z - ray_origin.z) * divz;
	}
	else {
		tzmin = (boundingBoxMax.z - ray_origin.z) * divz;
		tzmax = (boundingBoxMin.z - ray_origin.z) * divz;
	}
	if ((tmin > tzmax) || (tzmin > tmax))
		return false; // Intersection not detected

	return true; // Intersection detected
}
