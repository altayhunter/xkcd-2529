#pragma once
#include "point.h"

typedef struct {
	unsigned capacity;
	unsigned size;
	Point* array;
} PointVector;

PointVector point_vector_new(unsigned capacity);

unsigned point_vector_size(const PointVector* pv);

Point point_vector_at(const PointVector* pv, unsigned i);

void point_vector_push_back(PointVector* pv, Point p);

void point_vector_destroy(PointVector* pv);
