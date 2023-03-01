#include "walker.hpp" // Walker
#include <cassert>    // assert
#include <iostream>   // cout

using namespace std;

int main() {
	// No marbles
	{
		Walker w(0, 5);
		assert(w.steps() == 1);
		assert(w.intersections() == 0);
	}
	// No steps
	{
		Walker w(4, 0);
		assert(w.steps() == 1);
		assert(w.intersections() == 0);
	}
	// Double zero
	{
		Walker w(0, 0);
		assert(w.steps() == 1);
		assert(w.intersections() == 0);
	}
	// Marble placement
	{
		Walker w(4, 1);
		assert(w.firstMarbleParity());
	}
	// Normal inputs
	{
		Walker w(3, 5);
		assert(w.steps() >= 8);
		assert(w.steps() <= 16);
		assert(w.intersections() >= 2);
		assert(w.intersections() <= 5);
	}
	cout << "Test passed.\n";
	return 0;
}
