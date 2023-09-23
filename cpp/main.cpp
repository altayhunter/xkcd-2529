#include "walker.hpp" // Walker
#include <cstdint>    // uint64_t
#include <future>     // async
#include <iostream>   // cout
#include <numeric>    // accumulate
#include <thread>     // hardware_concurrency
#include <utility>    // make_pair

using namespace std;

pair<uint64_t, uint64_t> worker(unsigned n, unsigned k, unsigned runs) {
	uint64_t steps = 0;
	uint64_t intersections = 0;
	for (unsigned i = 0; i < runs; i++) {
		Walker w(n, k);
		steps += w.steps();
		intersections += w.intersections();
	}
	return make_pair(steps, intersections);
}

pair<double, double> compute_averages(unsigned n, unsigned k, unsigned runs) {
	unsigned cores = thread::hardware_concurrency();
	vector<future<pair<uint64_t, uint64_t>>> futures;
	futures.reserve(cores);
	unsigned each = runs / cores;
	unsigned extra = runs % cores;
	futures.emplace_back(async(launch::async, worker, n, k, each + extra));
	for (unsigned i = 0; i < cores - 1; i++) {
		futures.emplace_back(async(launch::async, worker, n, k, each));
	}
	uint64_t steps = 0;
	uint64_t intersections = 0;
	for (auto& f : futures) {
		auto [s, i] = f.get();
		steps += s;
		intersections += i;
	}
	return make_pair(
		steps / static_cast<double>(runs),
		intersections / static_cast<double>(runs)
	);
}

int main() {
	unsigned n = 4;
	unsigned k = 1000;
	unsigned runs = 1000000;
	auto [steps, intersections] = compute_averages(n, k, runs);
	cout << "Average of " << runs << " runs is " << steps
			<< " steps and " << intersections
			<< " intersections" << endl;
	return 0;
};
