package main

import "fmt"

type BestLine struct {
	points uint
	best_fit Line
}

func NewBestLine(points []Point) *BestLine {
	if len(points) < 2 {
		zero := Point{0, 0}
		return &BestLine{uint(len(points)), *NewLine(zero, zero)}
	}
	max_i := uint(0)
	max_l := *NewLine(points[0], points[1])
	for i, a := range points {
		for j, b := range points[i+1:] {
			l := *NewLine(a, b)
			intersections := uint(2)
			for _, c := range points[i+j+2:] {
				if l.intersects(c) {
					intersections += 1
				}
			}
			if intersections > max_i {
				max_i = intersections
				max_l = l
			}
		}
	}
	return &BestLine{max_i, max_l}
}

func (bl BestLine) intersections() uint {
	return bl.points
}

func (bl BestLine) String() string {
	return fmt.Sprintf("%v", bl.best_fit)
}
