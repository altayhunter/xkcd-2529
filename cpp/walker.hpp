#include "point.hpp"                      // Point
#include <absl/container/flat_hash_set.h> // flat_hash_set
#include <vector>                         // vector

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
	absl::flat_hash_set<Point> visited;
};
