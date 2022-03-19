package main

import (
	"math"
	"testing"
)

func TestN1K1000(t *testing.T) {
	n := uint(1)
	k := uint(1000)
	runs := uint(100)
	steps, intersections := compute_averages(n, k, runs)
	if math.Abs(steps - 71.95) > 17.5 {
		t.Errorf("Expected %f to be within 17.5 of 71.95", steps);
	}
	if math.Abs(intersections - 11.0) > 1.6 {
		t.Errorf("Expected %f to be within 1.6 of 11.0", intersections);
	}
}

func TestN2K1000(t *testing.T) {
	n := uint(2)
	k := uint(1000)
	runs := uint(1000)
	steps, intersections := compute_averages(n, k, runs)
	if math.Abs(steps - 71.95) > 7.0 {
		t.Errorf("Expected %f to be within 7.0 of 71.95", steps);
	}
	if math.Abs(intersections - 7.44) > 0.35 {
		t.Errorf("Expected %f to be within 0.35 of 7.44", intersections);
	}
}

func TestN3K1000(t *testing.T) {
	n := uint(3)
	k := uint(1000)
	runs := uint(1000)
	steps, intersections := compute_averages(n, k, runs)
	if math.Abs(steps - 71.95) > 7.0 {
		t.Errorf("Expected %f to be within 7.0 of 71.95", steps);
	}
	if math.Abs(intersections - 4.57) > 0.3 {
		t.Errorf("Expected %f to be within 0.3 of 4.57", intersections);
	}
}

func TestN4K1000(t *testing.T) {
	n := uint(4)
	k := uint(1000)
	runs := uint(1000)
	steps, intersections := compute_averages(n, k, runs)
	if math.Abs(steps - 71.95) > 7.0 {
		t.Errorf("Expected %f to be within 7.0 of 71.95", steps);
	}
	if math.Abs(intersections - 4.37) > 0.2 {
		t.Errorf("Expected %f to be within 0.2 of 4.37", intersections);
	}
}

func TestN5K1000(t *testing.T) {
	n := uint(5)
	k := uint(1000)
	runs := uint(1000)
	steps, intersections := compute_averages(n, k, runs)
	if math.Abs(steps - 71.95) > 7.0 {
		t.Errorf("Expected %f to be within 7.0 of 71.95", steps);
	}
	if math.Abs(intersections - 3.33) > 0.2 {
		t.Errorf("Expected %f to be within 0.2 of 3.33", intersections);
	}
}
