#pragma once
#include <stdint.h> // int32_t

typedef struct {
	int32_t x;
	int32_t y;
} Point;

Point point_neighbor_up(Point p);

Point point_neighbor_right(Point p);

Point point_neighbor_down(Point p);

Point point_neighbor_left(Point p);

void* point_to_void(Point p);

Point point_from_void(const void* v);
