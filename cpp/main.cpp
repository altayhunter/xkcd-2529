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
