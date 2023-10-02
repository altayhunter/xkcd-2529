#include "point_vector.h" // Point, PointVector
#include <stdlib.h>       // malloc, realloc, free

PointVector point_vector_new(unsigned capacity) {
	if (capacity < 1) capacity = 1;
	return (PointVector) {
		.capacity = capacity,
		.size = 0,
		.array = (Point*)malloc(sizeof(Point[capacity])),
	};
}

unsigned point_vector_size(const PointVector* pv) {
	return pv->size;
}

Point point_vector_at(const PointVector* pv, unsigned i) {
	return pv->array[i];
}

void point_vector_expand(PointVector* pv) {
	pv->capacity *= 2;
	pv->array = realloc(pv->array, sizeof(Point[pv->capacity]));
}

void point_vector_push_back(PointVector* pv, Point p) {
	if (pv->capacity <= pv->size) {
		point_vector_expand(pv);
	}
	pv->array[pv->size] = p;
	pv->size += 1;
}

void point_vector_destroy(PointVector* pv) {
	free(pv->array);
}
