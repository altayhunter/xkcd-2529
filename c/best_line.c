#include "best_line.h" // Point, PointVector
#include <math.h>      // isfinite
#include <stdbool.h>   // bool

typedef struct {
	double slope;
	double intercept;
} Line;

Line line_from(Point a, Point b) {
	double slope = (a.y - b.y) / (double)(a.x - b.x);
	double intercept = a.x == b.x ? a.x : a.y - slope * a.x;
	return (Line) { .slope = slope, .intercept = intercept };
}

bool intersects(Line l, Point p) {
	if (!isfinite(l.slope)) {
		return p.x == l.intercept;
	}
	return p.y == l.slope * p.x + l.intercept;
}

uint32_t best_line_intersections(PointVector pv) {
	unsigned size = point_vector_size(&pv);
	if (size < 2) {
		return 0;
	}
	unsigned most_points = 2;
	for (unsigned i = 0; i < size - 1; i++) {
		for (unsigned j = i + 1; j < size; j++) {
			Point a = point_vector_at(&pv, i);
			Point b = point_vector_at(&pv, j);
			Line l = line_from(a, b);
			unsigned intersections = 2;
			for (unsigned k = j + 1; k < size; k++) {
				if (intersects(l, point_vector_at(&pv, k))) {
					intersections++;
				}
			}
			if (intersections > most_points) {
				most_points = intersections;
			}
		}
	}
	return most_points;
}
