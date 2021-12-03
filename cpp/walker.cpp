#include "walker.hpp"    // Walker
#include "best_line.hpp" // BestLine
#include "point.hpp"     // Point
#include <ctime>         // time
#include <functional>    // bind
#include <random>        // uniform_int_distribution, default_random_engine

Walker::Walker(unsigned n, unsigned k) {
	Point location(0, 0);
	visited.insert(location);
	if (n == 0 || k == 0) return;
	while (!trapped(location)) {
		Point desired = randomNeighbor(location);
		while (visited.contains(desired)) {
			desired = randomNeighbor(location);
		}
		if (visited.size() % n == 0) {
			marbles.push_back(desired);
		}
		visited.insert(desired);
		location = desired;
		if (visited.size() > n * k) break;
	}
}

int Walker::intersections() const {
	return BestLine(marbles).intersections();
}

int Walker::steps() const {
	return visited.size();
}

Point Walker::randomNeighbor(const Point& p) const {
	static auto gen = bind(
			std::uniform_int_distribution<>(0, 3),
			std::default_random_engine(std::time(0)));
	switch (gen()) {
		case 0: return Point(p.x, p.y + 1);
		case 1: return Point(p.x + 1, p.y);
		case 2: return Point(p.x, p.y - 1);
		default: return Point(p.x - 1, p.y);
	}
}

bool Walker::trapped(const Point& p) const {
	return
		visited.contains(Point(p.x, p.y + 1)) &&
		visited.contains(Point(p.x + 1, p.y)) &&
		visited.contains(Point(p.x, p.y - 1)) &&
		visited.contains(Point(p.x - 1, p.y));
}
