#include "point.hpp"    // Point
#include "pp_line.hpp"  // Line
#include "rational.hpp" // Rational

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
