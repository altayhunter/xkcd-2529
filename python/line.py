#!/usr/bin/python
from fractions import Fraction

class Point:
	def __init__(self, x: int, y: int):
		self.x = x
		self.y = y
	def __repr__(self) -> str:
		return "(%d,%d)" % (self.x, self.y)
	def __hash__(self) -> int:
		return hash(self.__repr__())
	def __eq__(self, point) -> bool:
		if isinstance(point, Point):
			return self.x == point.x and self.y == point.y
		return False

class Line:
	def __init__(self, a: Point, b: Point):
		self.point = a
		deltaX = a.x - b.x
		deltaY = a.y - b.y
		if deltaX == 0:
			self.slope = 'inf'
		else:
			self.slope = Fraction(deltaY, deltaX)
	def intersects(self, p: Point):
		deltaX = p.x - self.point.x
		deltaY = p.y - self.point.y
		if self.slope == 'inf':
			return self.point.x == p.x
		elif deltaX == 0:
			return False
		return self.slope == Fraction(deltaY, deltaX)
