#include "point.hpp"   // Point
#include "pp_line.hpp" // Line
#include <cassert>     // assert
#include <iostream>    // cout
#include <sstream>     // stringstream

using namespace std;

int main() {
	// Vertical line
	{
		auto a = Point(5, 7);
		auto b = Point(5, 3);
		Line l(a, b);
		auto c = Point(5, 9);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "5,7 1/0");
	}
	// Horizontal line
	{
		auto a = Point(7, 5);
		auto b = Point(3, 5);
		Line l(a, b);
		auto c = Point(9, 5);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "7,5 0");
	}
	// Positive slope
	{
		auto a = Point(1, 2);
		auto b = Point(5, 4);
		Line l(a, b);
		auto c = Point(7, 5);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "1,2 1/2");
	}
	// Negative slope
	{
		auto a = Point(1, 4);
		auto b = Point(5, 2);
		Line l(a, b);
		auto c = Point(3, 3);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "1,4 -1/2");
	}
	// Coprime points
	{
		auto a = Point(10, 14);
		auto b = Point(25, 35);
		Line l(a, b);
		auto c = Point(0, 0);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "10,14 7/5");
	}
	// Same points
	{
		auto a = Point(0, 0);
		auto b = Point(0, 0);
		Line l(a, b);
		stringstream ss;
		ss << l;
		assert(ss.str() == "0,0 1/0");
	}
	cout << "Test passed.\n";
	return 0;
}
