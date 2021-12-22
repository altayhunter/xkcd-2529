#include "point.hpp"  // Point
#include <functional> // hash

bool operator<(const Point& a, const Point& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}

size_t Point::Hash::operator()(const Point& p) const {
	size_t x = std::hash<int>()(p.x);
	size_t y = std::hash<int>()(p.y) << 16;
	return x ^ y;
}
