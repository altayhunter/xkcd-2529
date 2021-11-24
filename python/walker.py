#!/usr/bin/python
from bestline import BestLine
from line import Point
from random import randrange

class Walker:
	def __init__(self, n: int, k: int):
		self.marbles = []
		self.visited = set()
		location = Point(0, 0)
		if n == 0 or k == 0: return
		while not self.__trapped(location):
			desired = self.__randomNeighbor(location)
			while desired in self.visited:
				desired = self.__randomNeighbor(location)
			if len(self.visited) % n == 0:
				self.marbles.append(desired)
			self.visited.add(desired)
			location = desired
			if len(self.visited) > n * k: break
	def __trapped(self, p: Point) -> bool:
		return (
			Point(p.x, p.y + 1) in self.visited and
			Point(p.x + 1, p.y) in self.visited and
			Point(p.x, p.y - 1) in self.visited and
			Point(p.x - 1, p.y) in self.visited
		)
	def __randomNeighbor(self, p: Point) -> Point:
		direction = randrange(4)
		if direction == 0:
			return Point(p.x, p.y + 1)
		elif direction == 1:
			return Point(p.x + 1, p.y)
		elif direction == 2:
			return Point(p.x, p.y - 1)
		else:
			return Point(p.x - 1, p.y)
	def intersections(self) -> int:
		return BestLine(self.marbles).numPoints
