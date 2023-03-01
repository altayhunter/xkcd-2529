package main

import "testing"

func TestNoMarbles(t *testing.T) {
	w := *NewWalker(0, 5)
	if w.steps() != 1 {
		t.Errorf("Expected %d to match 1", w.steps())
	}
	if w.intersections() != 0 {
		t.Errorf("Expected %d to match 0", w.intersections())
	}
}

func TestNoSteps(t *testing.T) {
	w := *NewWalker(4, 0)
	if w.steps() != 1 {
		t.Errorf("Expected %d to match 1", w.steps())
	}
	if w.intersections() != 0 {
		t.Errorf("Expected %d to match 0", w.intersections())
	}
}

func TestDoubleZero(t *testing.T) {
	w := *NewWalker(0, 0)
	if w.steps() != 1 {
		t.Errorf("Expected %d to match 1", w.steps())
	}
	if w.intersections() != 0 {
		t.Errorf("Expected %d to match 0", w.intersections())
	}
}

func TestMarblePlacement(t *testing.T) {
	w := *NewWalker(4, 1)
	if len(w.marbles) != 1 {
		t.Errorf("Expected %d to match 1", len(w.marbles))
	}
	hasEvenParity := func(p Point) bool { return (p.x + p.y) % 2 == 0 }
	if !hasEvenParity(w.marbles[0]) {
		t.Errorf("Expected %s to have even parity", w.marbles[0])
	}
}

func TestNormalInputs(t *testing.T) {
	w := *NewWalker(3, 5)
	if w.steps() < 8 {
		t.Errorf("Expected %d to be at least 8", w.steps())
	}
	if w.steps() > 16 {
		t.Errorf("Expected %d to be less than 17", w.steps())
	}
	if w.intersections() < 2 {
		t.Errorf("Expected %d to be greater than 1", w.intersections())
	}
	if w.intersections() > 5 {
		t.Errorf("Expected %d to be less than 6", w.steps())
	}
}
