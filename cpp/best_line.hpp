#include "point.hpp"   // Point
#include "si_line.hpp" // Line
#include <vector>      // vector

class BestLine {
public:
	BestLine(const std::vector<Point>& points);
	int intersections() const;
private:
	int numPoints = 0;
	Line bestFit;

	friend std::ostream& operator<<(std::ostream& out, const BestLine& bl);
};
