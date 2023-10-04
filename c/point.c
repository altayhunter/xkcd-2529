#include "point.h"  // Point

Point point_neighbor_up(Point p) {
	return (Point) { .x = p.x, .y = p.y + 1 };
}

Point point_neighbor_right(Point p) {
	return (Point) { .x = p.x + 1, .y = p.y };
}

Point point_neighbor_left(Point p) {
	return (Point) { .x = p.x - 1, .y = p.y };
}

Point point_neighbor_down(Point p) {
	return (Point) { .x = p.x, .y = p.y - 1 };
}

void* point_to_void(Point p) {
	uintptr_t v = 0;
	v |= (uint32_t)p.x;
	v <<= 32;
	v |= (uint32_t)p.y;
	return (void*)v;
}

Point point_from_void(const void* v) {
	uint32_t y = (uintptr_t)v & 0xffffffff;
	uint32_t x = ((uintptr_t)v >> 32);
	return (Point) { .x = x, .y = y };
}
