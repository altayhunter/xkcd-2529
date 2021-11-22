#include "rational.hpp" // Rational
#include <cassert>      // assert
#include <iostream>     // cout
#include <limits>       // numeric_limits
#include <sstream>      // stringstream

using namespace std;

int main() {
	// Default constructor
	{
		Rational r;
		stringstream ss;
		ss << r;
		assert(ss.str() == "0");
	}
	// Numerator only
	{
		Rational r(7);
		stringstream ss;
		ss << r;
		assert(ss.str() == "7");
	}
	// Simple form
	{
		Rational r(70, 42);
		stringstream ss;
		ss << r;
		assert(ss.str() == "5/3");
	}
	// Negative denominator
	{
		Rational r(9, -12);
		stringstream ss;
		ss << r;
		assert(ss.str() == "-3/4");
	}
	// Double negative
	{
		Rational r(-9, -27);
		stringstream ss;
		ss << r;
		assert(ss.str() == "1/3");
	}
	// Decimal form
	{
		Rational r(1, 2);
		assert(r.decimal() == 0.5);
	}
	// Divide by zero
	{
		Rational r(10, 0);
		stringstream ss;
		ss << r;
		assert(ss.str() == "1/0");
		assert(r.decimal() == numeric_limits<double>::infinity());
	}
	cout << "Test passed.\n";
	return 0;
}
