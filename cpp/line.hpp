#pragma once
#include "rational.hpp" // Rational
#include <ostream>      // ostream

struct Point {
	int x = 0;
	int y = 0;
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}
	struct Hash {
		size_t operator()(const Point& p) const;
	};
};

bool operator<(const Point& a, const Point& b);
bool operator==(const Point& a, const Point& b);

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
