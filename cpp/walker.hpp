#include "line.hpp"   // Point
#include <set>        // set
#include <vector>     // vector

class Walker {
public:
	Walker(unsigned n, unsigned k);
	int intersections() const;
	int steps() const;
private:
	Point randomNeighbor(const Point& p) const;
	bool trapped(const Point& p) const;
	std::vector<Point> marbles;
	std::set<Point> visited;
};
