#!/usr/bin/pypy3
from __future__ import annotations
from math import isfinite

class Point:
	def __init__(self, x: int, y: int):
		self.x = x
		self.y = y
	def up(self) -> Point:
		return Point(self.x, self.y + 1)
	def right(self) -> Point:
		return Point(self.x + 1, self.y)
	def down(self) -> Point:
		return Point(self.x, self.y - 1)
	def left(self) -> Point:
		return Point(self.x - 1, self.y)
	def __repr__(self) -> str:
		return "(%d,%d)" % (self.x, self.y)
	def __hash__(self) -> int:
		return (self.y << 16) ^ self.x
	def __eq__(self, point) -> bool:
		if isinstance(point, Point):
			return self.x == point.x and self.y == point.y
		return False

class Line:
	def __init__(self, a: Point, b: Point):
		self.slope = float('inf') if a.x - b.x == 0 else (a.y - b.y) / (a.x - b.x)
		self.intercept = a.x if a.x == b.x else a.y - self.slope * a.x
	def intersects(self, p: Point) -> bool:
		if not isfinite(self.slope):
			return p.x == self.intercept
		return p.y == self.slope * p.x + self.intercept
	def __repr__(self) -> str:
		if not isfinite(self.slope):
			return "x = %d" % self.intercept
		return "y = %dx + %d" % (self.slope, self.intercept)
