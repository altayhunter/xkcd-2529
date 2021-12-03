#pragma once
#include "point.hpp" // Point
#include <ostream>   // ostream

class Line {
public:
	Line() = default;
	Line(const Point& a, const Point& b) :
			slope(static_cast<double>(a.y - b.y) / (a.x - b.x)),
			intercept(a.x == b.x ? a.x : a.y - slope * a.x) {}
	bool intersects(const Point& p) const;
private:
	double slope;
	double intercept;

	friend bool operator==(const Line& a, const Line& b);
	friend std::ostream& operator<<(std::ostream& out, const Line& l);
};
