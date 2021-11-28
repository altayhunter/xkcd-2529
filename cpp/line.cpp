#include "line.hpp"     // Line, Point
#include "rational.hpp" // Rational

bool operator<(const Point& a, const Point& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}

size_t Point::Hash::operator()(const Point& p) const {
	size_t x = std::hash<int>()(p.x);
	size_t y = std::hash<int>()(p.y) << 1;
	return x ^ y;
}

bool Line::intersects(const Point& p) const {
	int deltaX = p.x - point.x;
	int deltaY = p.y - point.y;
	return slope == Rational(deltaY, deltaX);
}

bool operator==(const Line& a, const Line& b) {
	return a.intersects(b.point);
}

std::ostream& operator<<(std::ostream& out, const Line& l) {
	return out << l.point.x << "," << l.point.y << " " << l.slope;
}
