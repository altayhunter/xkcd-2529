#!/usr/bin/pypy3
from bestline import BestLine
from line import Point
from random import Random

class Walker:
	def __init__(self, n: int, k: int, random: Random):
		self.random = random
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
		match self.random.randrange(4):
			case 0: return p.up()
			case 1: return p.right()
			case 2: return p.down()
			case _: return p.left()
	def intersections(self) -> int:
		return BestLine(self.marbles).numPoints
