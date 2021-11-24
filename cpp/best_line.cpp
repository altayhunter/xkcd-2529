#include "best_line.hpp"  // BestLine
#include <algorithm>      // count_if
#include <cassert>        // assert
#include <vector>         // vector

BestLine::BestLine(const std::vector<Point>& points) {
	if (points.size() < 2) {
		numPoints = points.size();
		return;
	}
	for (unsigned i = 0; i < points.size() - 1; i++) {
		for (unsigned j = i + 1; j < points.size(); j++) {
			Point a = points[i];
			Point b = points[j];
			Line l(a, b);
			int intersections =
					2 + std::count_if(points.begin() + j + 1, points.end(),
					[&l](Point p){ return l.intersects(p); });
			if (intersections > numPoints) {
				numPoints = intersections;
				bestFit = l;
			}
		}
	}
}

int BestLine::intersections() const {
	return numPoints;
}

std::ostream& operator<<(std::ostream& out, const BestLine& bl) {
	return out << bl.numPoints << " intersections (" << bl.bestFit << ")";
}
