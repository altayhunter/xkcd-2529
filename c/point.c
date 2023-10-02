#include "point.h"  // Point
#include <stdlib.h> // malloc, free

Point* point_new(Point p) {
	Point* q = (Point*)malloc(sizeof(Point));
	q->x = p.x;
	q->y = p.y;
	return q;
}

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

void point_destroy(void* p) {
	free((Point*)p);
}
