// https://xkcd.com/2529
#include "walker.hpp" // Walker
#include <iostream>   // cout
#include <numeric>    // accumulate

using namespace std;

int main() {
	unsigned n = 4;
	unsigned k = 1000;
	vector<uint64_t> steps;
	vector<uint64_t> intersections;
	for (int i = 0; i < 1000000; i++) {
		Walker w(n, k);
		steps.push_back(w.steps());
		intersections.push_back(w.intersections());
	}
	double avgSteps =
			1.0 * accumulate(steps.begin(), steps.end(), 0) / steps.size();
	double avgIntersections =
			1.0 * accumulate(intersections.begin(), intersections.end(), 0) /
			intersections.size();
	cout << "Average of " << steps.size() << " runs is " << avgSteps
			<< " steps and " << avgIntersections << " intersections" << endl;
	return 0;
};

// Results:
//  n=10, k=1000
//  71.7 steps, 2.47 intersections
//  n=9, k=1000
//  71.7 steps, 2.42 intersections
//  n=8, k=1000
//  71.7 steps, 2.81 intersections
//  n=7, k=1000
//  71.7 steps, 2.75 intersections
//  n=6, k=1000
//  71.8 steps, 3.34 intersections
//  n=5, k=1000
//  71.8 steps, 3.33 intersections
//  n=4, k=1000
//  71.7 steps, 4.37 intersections
//  n=3, k=1000
//  71.8 steps, 4.57 intersections
//  n=2, k=1000
//  71.8 steps, 7.44 intersections
//  n=1, k=1000
//  71.7308 steps, 11.012 intersections
