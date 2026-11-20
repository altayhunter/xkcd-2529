#pragma once
#include <cuchar>           // size_t
#include <absl/hash/hash.h> // AbslHashValue

struct Point {
	int x = 0;
	int y = 0;
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}

	template <typename H>
	friend H AbslHashValue(H h, const Point& p) {
		return H::combine(std::move(h), p.x, p.y);
	}
};

bool operator<(const Point& a, const Point& b);
bool operator==(const Point& a, const Point& b);
