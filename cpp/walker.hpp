#include "point.hpp"     // Point
#include <unordered_set> // unordered_set
#include <vector>        // vector

class Walker {
public:
	Walker(unsigned n, unsigned k);
	int intersections() const;
	int steps() const;
	bool firstMarbleParity() const;
private:
	Point randomNeighbor(const Point& p) const;
	bool trapped(const Point& p) const;
	std::vector<Point> marbles;
	std::unordered_set<Point, Point::Hash> visited;
};
