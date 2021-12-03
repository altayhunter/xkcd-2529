#pragma once
#include <cuchar> // size_t

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
