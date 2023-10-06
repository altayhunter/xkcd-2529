#!/usr/bin/pypy3
import os
import sys
from walker import Walker
from concurrent.futures import ProcessPoolExecutor
from random import Random

def sum_range(n: int, k: int, runs: int) -> (int, int):
	steps = 0
	intersections = 0
	random = Random()
	for _ in range(runs):
		w = Walker(n, k, random)
		steps += len(w.visited)
		intersections += w.intersections()
	return (steps, intersections)

def compute_averages(n: int, k: int, runs: int) -> (float, float):
	cores = os.cpu_count()
	futures = []
	each = runs // cores
	extra = runs % cores
	steps = 0
	intersections = 0
	with ProcessPoolExecutor() as executor:
		futures.append(executor.submit(sum_range, n, k, each + extra))
		for _ in range(cores - 1):
			futures.append(executor.submit(sum_range, n, k, each))
		for f in futures:
			steps += f.result()[0]
			intersections += f.result()[1]
	return (steps / runs, intersections / runs)

def main() -> int:
	n = 4
	k = 1000
	runs = 1000000
	(steps, intersections) = compute_averages(n, k, runs)
	print('Average of', runs, 'runs is', steps,
			'steps and', intersections, 'intersections')
	return 0

if __name__ == '__main__':
	sys.exit(main())
