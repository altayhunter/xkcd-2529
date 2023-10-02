#include <assert.h> // assert
#include <stdio.h>  // printf
#include "point.h"  // Point
#include "point.c"

int main() {
	// Up neighbor
	{
		Point p = (Point) { .x = -4, .y = 7 };
		Point q = point_neighbor_up(p);
		assert(q.x == -4);
		assert(q.y == 8);
	}
	// Right neighbor
	{
		Point p = (Point) { .x = -4, .y = 7 };
		Point q = point_neighbor_right(p);
		assert(q.x == -3);
		assert(q.y == 7);
	}
	// Down neighbor
	{
		Point p = (Point) { .x = -4, .y = 7 };
		Point q = point_neighbor_down(p);
		assert(q.x == -4);
		assert(q.y == 6);
	}
	// Left neighbor
	{
		Point p = (Point) { .x = -4, .y = 7 };
		Point q = point_neighbor_left(p);
		assert(q.x == -5);
		assert(q.y == 7);
	}
	printf("Test passed.\n");
	return 0;
}
