#include "line.hpp"     // Line, Point
#include "rational.hpp" // Rational

bool operator<(const Point& a, const Point& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
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
