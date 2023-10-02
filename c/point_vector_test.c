
#include <assert.h>       // assert
#include <stdio.h>        // printf
#include "point_vector.h" // PointVector
#include "point_vector.c"

int main() {
	// Vector initialization
	{
		PointVector pv = point_vector_new(0);
		assert(point_vector_size(&pv) == 0);
		point_vector_destroy(&pv);
	}
	// Vector capacity
	{
		PointVector pv = point_vector_new(1);
		assert(pv.capacity == 1);
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 0 });
		assert(pv.capacity == 1);
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 0 });
		assert(pv.capacity == 2);
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 0 });
		assert(pv.capacity == 4);
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 0 });
		assert(pv.capacity == 4);
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 0 });
		assert(pv.capacity == 8);
		point_vector_destroy(&pv);
	}
	// Vector contents
	{
		PointVector pv = point_vector_new(0);
		point_vector_push_back(&pv, (Point) { .x = 2, .y = 5 });
		point_vector_push_back(&pv, (Point) { .x = 7, .y = 1 });
		point_vector_push_back(&pv, (Point) { .x = 0, .y = 9 });
		Point first = point_vector_at(&pv, 0);
		assert(first.x == 2);
		assert(first.y == 5);
		Point second = point_vector_at(&pv, 1);
		assert(second.x == 7);
		assert(second.y == 1);
		Point third = point_vector_at(&pv, 2);
		assert(third.x == 0);
		assert(third.y == 9);
		point_vector_destroy(&pv);
	}
	printf("Test passed.\n");
	return 0;
}
