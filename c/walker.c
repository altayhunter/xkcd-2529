#include "walker.h"       // WalkResults
#include <assert.h>       // assert
#include <glib.h>         // g_hash_table
#include <stdio.h>        // printf
#include <stdlib.h>       // rand
#include "best_line.h"    // best_line_intersections
#include "point.h"        // Point
#include "point_vector.h" // point_vector

guint32 rotate_left_five(guint32 value) {
	return (value << 5) | (value >> 27);
}

guint32 add_to_hash(guint32 hash, guint32 value) {
	guint32 golden_ratio = 0x9E3779B9U;
	return golden_ratio * (rotate_left_five(hash) ^ value);
}

guint32 fx_hash(gconstpointer key) {
	guint32 hash = 0;
	Point p = point_from_void(key);
	hash = add_to_hash(hash, p.x);
	hash = add_to_hash(hash, p.y);
	return hash;
}

typedef enum {
	Up,
	Right,
	Down,
	Left,
} Direction;

Direction random_direction(Direction d) {
	unsigned random = rand() % 3;
	switch (d) {
		case Up:
			switch (random) {
				case 0: return Up;
				case 1: return Right;
				case 2: return Left;
			}
		case Right:
			switch (random) {
				case 0: return Up;
				case 1: return Right;
				case 2: return Down;
			}
		case Left:
			switch (random) {
				case 0: return Up;
				case 1: return Down;
				case 2: return Left;
			}
		case Down:
			switch (random) {
				case 0: return Right;
				case 1: return Down;
				case 2: return Left;
			}
	}
	assert(!"Unexpected direction!");
	return Up; // To suppress warning
}

Point neighbor(Point p, Direction d) {
	switch (d) {
		case Up: return point_neighbor_up(p);
		case Right: return point_neighbor_right(p);
		case Left: return point_neighbor_left(p);
		case Down: return point_neighbor_down(p);
	}
	assert(!"Unexpected direction!");
}


Direction valid_direction(GHashTable* visited, Point p, Direction d) {
	Direction rd = random_direction(d);
	Point n = neighbor(p, rd);
	while (g_hash_table_contains(visited, point_to_void(n))) {
		rd = random_direction(d);
		n = neighbor(p, rd);
	}
	return rd;
}

gboolean trapped(GHashTable* visited, Point p) {
	Point up = point_neighbor_up(p);
	Point right = point_neighbor_right(p);
	Point down = point_neighbor_down(p);
	Point left = point_neighbor_left(p);
	return
		g_hash_table_contains(visited, point_to_void(up)) &&
		g_hash_table_contains(visited, point_to_void(right)) &&
		g_hash_table_contains(visited, point_to_void(down)) &&
		g_hash_table_contains(visited, point_to_void(left));
}

WalkResults walk(unsigned n, unsigned k) {
	if (n == 0 || k == 0) {
		return (WalkResults) {
			.steps = 1,
			.intersections = 0,
		};
	}
	GHashTable* visited = g_hash_table_new(fx_hash, NULL);
	Point location = (Point) { .x = 0, .y = 0 };
	g_hash_table_add(visited, point_to_void(location));
	location = (Point) { .x = 0, .y = 1 };
	g_hash_table_add(visited, point_to_void(location));
	Direction direction = Up;
	PointVector marbles = point_vector_new(1);
	if (n == 1) {
		point_vector_push_back(&marbles, location);
		if (k == 1) {
			return (WalkResults) {
				.steps = g_hash_table_size(visited),
				.intersections = best_line_intersections(marbles),
			};
		}
	}
	while (!trapped(visited, location)) {
		direction = valid_direction(visited, location, direction);
		location = neighbor(location, direction);
		g_hash_table_add(visited, point_to_void(location));
		if ((g_hash_table_size(visited) - 1) % n == 0) {
			point_vector_push_back(&marbles, location);
		}
		if (g_hash_table_size(visited) > n * k) {
			break;
		}
	}
	WalkResults results = (WalkResults) {
		.steps = g_hash_table_size(visited),
		.intersections = best_line_intersections(marbles),
	};
	g_hash_table_destroy(visited);
	return results;
}
