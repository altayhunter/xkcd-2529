#pragma once
#include "rational.hpp" // Rational
#include <ostream>      // ostream

struct Point {
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}
	int x = 0;
	int y = 0;
};

bool operator<(const Point& a, const Point& b);

class Line {
public:
	Line() = default;
	Line(const Point& a, const Point& b)
			: point(a), slope(a.y - b.y, a.x - b.x) {}
	bool intersects(const Point& p) const;
private:
	Point point;
	Rational slope;

	friend bool operator==(const Line& a, const Line& b);
	friend std::ostream& operator<<(std::ostream& out, const Line& l);
};
