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

func TestNormalInputs(t *testing.T) {
	w := *NewWalker(3, 5)
	if w.steps() < 8 {
		t.Errorf("Expected %d to be at least 8", w.steps())
	}
	if w.steps() > 21 {
		t.Errorf("Expected %d to be less than 22", w.steps())
	}
	if w.intersections() < 2 {
		t.Errorf("Expected %d to be greater than 1", w.intersections())
	}
}
