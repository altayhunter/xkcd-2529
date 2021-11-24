#!/usr/bin/python
import sys
from statistics import mean
from walker import Walker

def main() -> int:
	n = 4
	k = 1000
	steps = []
	intersections = []
	for i in range(0, 10000):
		w = Walker(n, k)
		steps.append(len(w.visited))
		intersections.append(w.intersections())
	avgSteps = mean(steps)
	avgIntersections = mean(intersections)
	print('Average of', len(steps), 'runs is', avgSteps,
			'steps and', avgIntersections, 'intersections')
	return 0

if __name__ == '__main__':
	sys.exit(main())
