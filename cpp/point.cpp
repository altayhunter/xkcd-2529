#include "point.hpp"  // Point
#include <functional> // hash

bool operator<(const Point& a, const Point& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}
