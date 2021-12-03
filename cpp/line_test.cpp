#include "line.hpp"  // Line
#include "point.hpp" // Point
#include <cassert>   // assert
#include <iostream>  // cout
#include <sstream>   // stringstream

using namespace std;

int main() {
	// Rounding error symmetric
	{
		auto a = Point(1001, 1);
		auto b = Point(-1000, -1);
		Line l(a, b);
		auto c = Point(0, 0);
		assert(!l.intersects(c));
		auto d = Point(3002, 3);
		assert(l.intersects(d));
		stringstream ss;
		ss << l;
		assert(ss.str() == "y = 0.0009995x + -0.00049975");
	}
	// Rounding error asymmetric
	{
		auto a = Point(100000, 100000);
		auto b = Point(-1, 0);
		Line l(a, b);
		auto c = Point(0, 1);
		assert(!l.intersects(c));
		auto d = Point(200001, 200000);
		stringstream ss;
		ss << l;
		assert(ss.str() == "y = 0.99999x + 0.99999");
	}
	// Vertical line
	{
		auto a = Point(5, 7);
		auto b = Point(5, 3);
		Line l(a, b);
		auto c = Point(5, 9);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "x = 5");
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
		assert(ss.str() == "y = 0x + 5");
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
		assert(ss.str() == "y = 0.5x + 1.5");
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
		assert(ss.str() == "y = -0.5x + 4.5");
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
		assert(ss.str() == "y = 1.4x + 0");
	}
	// Same point
	{
		auto a = Point(2, -5);
		auto b = Point(2, -5);
		Line l(a, b);
		auto c = Point(2, -5);
		assert(l.intersects(c));
		stringstream ss;
		ss << l;
		assert(ss.str() == "x = 2");
	}
	cout << "Test passed.\n";
	return 0;
}
