package main

import "testing"

func TestFourHorizontalThreeVertical(t *testing.T) {
	v := []Point{
		Point{0, 1},
		Point{1, 1},
		Point{1, 0},
		Point{2, 1},
		Point{1, 2},
		Point{3, 1},
	}
	bl := *NewBestLine(v)
	if bl.intersections() != 4 {
		t.Errorf("Expected %d to match 4", bl.intersections())
	}
	if bl.String() != "y = -0.000000x + 1.000000" {
		t.Errorf("Expected %v to match y = -0.000000x + 1.000000", bl.String())
	}
}

func TestThreeDiagonalTwoHorizontal(t *testing.T) {
	v := []Point{
		Point{3, 3},
		Point{5, 3},
		Point{2, 0},
		Point{4, 6},
	}
	bl := *NewBestLine(v)
	if bl.intersections() != 3 {
		t.Errorf("Expected %d to match 3", bl.intersections())
	}
	if bl.String() != "y = 3.000000x + -6.000000" {
		t.Errorf("Expected %v to match y = 3.000000x + -6.000000", bl.String())
	}
}
