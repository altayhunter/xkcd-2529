#include "line.hpp"  // Line
#include "point.hpp" // Point
#include <cmath>     // isfinite

bool Line::intersects(const Point& p) const {
	if (!std::isfinite(slope)) return p.x == intercept;
	// NOTE: Approximate equality is safer when comparing floats.
	// abs(a - b) <= min(a, b) * epsilon
	// However, it's also slower and unnecessary for these values.
	return p.y == slope * p.x + intercept;
}

bool operator==(const Line& a, const Line& b) {
	return a.slope == b.slope && a.intercept == b.intercept;
}

std::ostream& operator<<(std::ostream& out, const Line& l) {
	if (!std::isfinite(l.slope)) {
		return out << "x = " << l.intercept;
	}
	return out << "y = " << l.slope << "x + " << l.intercept;
}
