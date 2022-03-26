#!/usr/bin/python
from bestline import BestLine
from line import Point
from random import randrange

class Walker:
	def __init__(self, n: int, k: int):
		location = Point(0, 0)
		self.marbles = []
		self.visited = set([location])
		if n == 0 or k == 0: return
		while not self.__trapped(location):
			desired = self.__validNeighbor(location)
			if len(self.visited) % n == 0:
				self.marbles.append(desired)
			self.visited.add(desired)
			location = desired
			if len(self.visited) > n * k: break
	def __trapped(self, p: Point) -> bool:
		return (
			p.up() in self.visited and
			p.right() in self.visited and
			p.down() in self.visited and
			p.left() in self.visited
		)
	def __validNeighbor(self, p: Point) -> Point:
		neighbor = self.__randomNeighbor(p)
		while neighbor in self.visited:
			neighbor = self.__randomNeighbor(p)
		return neighbor
	def __randomNeighbor(self, p: Point) -> Point:
		direction = randrange(4)
		if direction == 0:
			return p.up()
		elif direction == 1:
			return p.right()
		elif direction == 2:
			return p.down()
		else:
			return p.left()
	def intersections(self) -> int:
		return BestLine(self.marbles).numPoints
