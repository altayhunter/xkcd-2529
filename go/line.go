package main

import "fmt"
import "math"

type Point struct {
	x int32
	y int32
}

func (p Point) up() Point {
	return Point{p.x, p.y + 1}
}

func (p Point) right() Point {
	return Point{p.x + 1, p.y}
}

func (p Point) down() Point {
	return Point{p.x, p.y - 1}
}

func (p Point) left() Point {
	return Point{p.x - 1, p.y}
}

func (p Point) String() string {
	return fmt.Sprintf("(%d, %d)", p.x, p.y)
}

type Line struct {
	slope     float64
	intercept float64
}

func NewLine(a Point, b Point) *Line {
	slope := float64(a.y-b.y) / float64(a.x-b.x)
	intercept := float64(a.x)
	if a.x != b.x {
		intercept = float64(a.y) - slope*float64(a.x)
	}
	return &Line{slope, intercept}
}

func (l Line) intersects(p Point) bool {
	if math.IsInf(l.slope, 0) || math.IsNaN(l.slope) {
		return float64(p.x) == l.intercept
	} else {
		return float64(p.y) == l.slope*float64(p.x)+l.intercept
	}
}

func (l Line) String() string {
	if math.IsInf(l.slope, 0) || math.IsNaN(l.slope) {
		return fmt.Sprintf("x = %f", l.intercept)
	} else {
		return fmt.Sprintf("y = %fx + %f", l.slope, l.intercept)
	}
}
