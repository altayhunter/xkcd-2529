#include <pthread.h> // pthread
#include <stdint.h>  // uint64_t
#include <stdio.h>   // printf
#include <stdlib.h>  // srand
#include <time.h>    // time
#include <unistd.h>  // sysconf
#include "walker.h"  // walk

typedef struct {
	unsigned n;
	unsigned k;
	unsigned runs;
	uint64_t steps;
	uint64_t intersections;
} WorkerData;

void* worker(void* args) {
	WorkerData* wd = (WorkerData*)args;
	for (unsigned i = 0; i < wd->runs; i++) {
		WalkResults wr = walk(wd->n, wd->k);
		wd->steps += wr.steps;
		wd->intersections += wr.intersections;
	}
	pthread_exit(NULL);
}

typedef struct {
	double steps;
	double intersections;
} Averages;

Averages compute_averages(unsigned n, unsigned k, unsigned runs) {
	unsigned cores = sysconf(_SC_NPROCESSORS_ONLN);
	pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t[cores]));
	WorkerData* args = (WorkerData*)malloc(sizeof(WorkerData[cores]));
	unsigned each = runs / cores;
	unsigned extra = runs % cores;
	args[0] = (WorkerData) {
		.n = n,
		.k = k,
		.runs = each + extra,
		.steps = 0,
		.intersections = 0,
	};
	pthread_create(&threads[0], NULL, worker, &args[0]);
	for (unsigned i = 1; i < cores; i++) {
		args[i] = (WorkerData) {
			.n = n,
			.k = k,
			.runs = each,
			.steps = 0,
			.intersections = 0,
		};
		pthread_create(&threads[i], NULL, worker, &args[i]);
	}
	uint64_t steps = 0;
	uint64_t intersections = 0;
	for (unsigned i = 0; i < cores; i++) {
		pthread_join(threads[i], NULL);
		steps += args[i].steps;
		intersections += args[i].intersections;
	}
	free(threads);
	free(args);
	return (Averages) {
		.steps = steps / (double)runs,
		.intersections = intersections / (double)runs,
	};
}

int main() {
	unsigned n = 4;
	unsigned k = 1000;
	unsigned runs = 1000000;
	srand(time(NULL));
	Averages a = compute_averages(n, k, runs);
	printf("Average of %d runs is %f steps and %f intersections\n",
			runs, a.steps, a.intersections);
	return 0;
}
