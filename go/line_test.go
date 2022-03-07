package main

import "testing"

func TestPointConstruction(t *testing.T) {
	origin := Point{0, 0}
	if origin.String() != "(0, 0)" {
		t.Errorf("Expected %v to match (0, 0)", origin)
	}
	negatives := Point{-5, -7}
	if negatives.String() != "(-5, -7)" {
		t.Errorf("Expected %v to match (-5, -7)", negatives)
	}
}

func TestPointNeighbors(t *testing.T) {
	point := Point{-4, 7}
	if point == point.right() {
		t.Errorf("Expected %v to not equal %v", point, point.right())
	}
	if point != point.left().right() {
		t.Errorf("Expected %v to equal %v", point, point.left().right())
	}
	if point != point.up().down() {
		t.Errorf("Expected %v to equal %v", point, point.up().down())
	}
	if point.up().right() != point.right().up() {
		t.Errorf("Expected %v to equal %v", point.up().right(), point.right().up())
	}
}

func TestLineNoRoundingErrorSymmetric(t *testing.T) {
	a := Point{1001, 1}
	b := Point{-1000, -1}
	l := *NewLine(a, b)
	c := Point{0, 0}
	if l.intersects(c) {
		t.Errorf("Expected %v not to intersect %v", l, c)
	}
	d := Point{3002, 3}
	if !l.intersects(d) {
		t.Errorf("Expected %v to intersect %v", l, d)
	}
	if l.String() != "y = 0.001000x + -0.000500" {
		t.Errorf("Expected %v to match y = 0.001000x + -0.000500", l)
	}
}

func TestLineNoRoundingErrorAsymmetric(t *testing.T) {
	a := Point{100000, 100000}
	b := Point{-1, 0}
	l := *NewLine(a, b)
	c := Point{0, 1}
	if l.intersects(c) {
		t.Errorf("Expected %v not to intersect %v", l, c)
	}
	d := Point{200001, 200000}
	if !l.intersects(d) {
		t.Errorf("Expected %v to intersect %v", l, d)
	}
	if l.String() != "y = 0.999990x + 0.999990" {
		t.Errorf("Expected %v to match y = 0.999990x + 0.999990", l)
	}
}

func TestLineLargestNoRoundingError(t *testing.T) {
	a := Point{134217726, 134217727}
	b := Point{-1, 134217726}
	l := *NewLine(a, b)
	c := Point{0, 134217726}
	if l.intersects(c) {
		t.Errorf("Expected %v not to intersect %v", l, c)
	}
	if l.String() != "y = 0.000000x + 134217726.000000" {
		t.Errorf("Expected %v to match 0.000000x + 134217726.000000", l)
	}
}

func TestLineSmallestRoundingError(t *testing.T) {
	a := Point{134217727, 134217728}
	b := Point{-1, 134217727}
	l := *NewLine(a, b)
	c := Point{0, 134217727}
	if !l.intersects(c) {
		t.Errorf("Expected %v to intersect %v", l, c)
	}
	if l.String() != "y = 0.000000x + 134217727.000000" {
		t.Errorf("Expected %v to match 0.000000x + 134217727.000000", l)
	}
}

func TestLineVertical(t *testing.T) {
	a := Point{5, 7}
	b := Point{5, 3}
	l := *NewLine(a, b)
	c := Point{5, 9}
	if !l.intersects(c) {
		t.Errorf("Expected %v to intersect %v", l, c)
	}
	if l.String() != "x = 5.000000" {
		t.Errorf("Expected %v to match x = 5.000000", l)
	}
}

func TestLineHorizontal(t *testing.T) {
	a := Point{7, 5}
	b := Point{3, 5}
	l := *NewLine(a, b)
	c := Point{9, 5}
	if !l.intersects(c) {
		t.Errorf("Expected %v to intersect %v", l, c)
	}
	if l.String() != "y = 0.000000x + 5.000000" {
		t.Errorf("Expected %v to match y = 0.000000x + 5.000000", l)
	}
}

func TestLineUpward(t *testing.T) {
	a := Point{1, 2}
	b := Point{5, 4}
	l := *NewLine(a, b)
	c := Point{7, 5}
	if !l.intersects(c) {
		t.Errorf("Expected %v to intersect %v", l, c)
	}
	if l.String() != "y = 0.500000x + 1.500000" {
		t.Errorf("Expected %v to match y = 0.500000x + 1.500000", l)
	}
}

func TestLineDownward(t *testing.T) {
	a := Point{1, 4}
	b := Point{5, 2}
	l := *NewLine(a, b)
	c := Point{3, 3}
	if !l.intersects(c) {
		t.Errorf("Expected %v to intersect %v", l, c)
	}
	if l.String() != "y = -0.500000x + 4.500000" {
		t.Errorf("Expected %v to match y = -0.500000x + 4.500000", l)
	}
}

func TestLineSamePoints(t *testing.T) {
	a := Point{2, -5}
	b := Point{2, -5}
	l := *NewLine(a, b)
	c := Point{-5, 2}
	if l.intersects(c) {
		t.Errorf("Expected %v to not intersect %v", l, c)
	}
	d := Point{2, 7}
	if !l.intersects(d) {
		t.Errorf("Expected %v to intersect %v", l, d)
	}
	if l.String() != "x = 2.000000" {
		t.Errorf("Expected %v to match x = 2.000000", l)
	}
}
