#include "walker.hpp" // Walker
#include <cstdint>    // uint64_t
#include <iostream>   // cout
#include <numeric>    // accumulate

using namespace std;

double average(const vector<uint64_t>& v) {
	uint64_t sum = accumulate(v.begin(), v.end(), 0);
	return static_cast<double>(sum) / v.size();
}

int main() {
	unsigned n = 4;
	unsigned k = 1000;
	unsigned runs = 1000000;
	vector<uint64_t> steps;
	vector<uint64_t> intersections;
	steps.reserve(runs);
	intersections.reserve(runs);
	for (unsigned i = 0; i < runs; i++) {
		Walker w(n, k);
		steps.push_back(w.steps());
		intersections.push_back(w.intersections());
	}
	cout << "Average of " << runs << " runs is " << average(steps)
			<< " steps and " << average(intersections)
			<< " intersections" << endl;
	return 0;
};
