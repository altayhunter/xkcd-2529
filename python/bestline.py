#!/usr/bin/pypy3
from line import Point
from line import Line

class BestLine:
	def __init__(self, points: list):
		if (len(points) < 2):
			self.numPoints = len(points)
			return
		self.numPoints = 0
		for i in range(0, len(points) - 1):
			for j in range(i + 1, len(points)):
				a = points[i]
				b = points[j]
				l = Line(a, b)
				intersections = 2 + sum(1 for p in points[j+1:] if l.intersects(p))
				if (intersections > self.numPoints):
					self.numPoints = intersections
					self.bestFit = l
