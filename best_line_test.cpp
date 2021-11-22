#include "best_line.hpp" // BestLine
#include <cassert>       // assert
#include <iostream>      // cout
#include <sstream>       // stringstream

using namespace std;

int main() {
	// Four horizontal, three vertical
	{
		vector<Point> v = {
			Point(0, 1),
			Point(1, 1),
			Point(1, 0),
			Point(2, 1),
			Point(1, 2),
			Point(3, 1),
		};
		BestLine bl(v);
		stringstream ss;
		ss << bl;
		cout << ss.str() << endl;
		assert(ss.str() == "4 intersections (0,1 0)");
	}
	// Three diagonal, two horizontal
	{
		vector<Point> v = {
			Point(3, 3),
			Point(5, 3),
			Point(2, 0),
			Point(4, 6),
		};
		BestLine bl(v);
		stringstream ss;
		ss << bl;
		cout << ss.str() << endl;
		assert(ss.str() == "3 intersections (3,3 3)");
	}
	cout << "Test passed.\n";
	return 0;
}
