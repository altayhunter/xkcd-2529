#pragma once
#include <stdint.h> // int32_t

typedef struct {
	int32_t x;
	int32_t y;
} Point;

Point* point_new(Point p);

Point point_neighbor_up(Point p);

Point point_neighbor_right(Point p);

Point point_neighbor_down(Point p);

Point point_neighbor_left(Point p);

void point_destroy(void* p);
