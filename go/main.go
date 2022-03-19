package main

import "fmt"
import "math/rand"
import "time"

func average(numbers []uint) float64 {
	total := uint(0)
	for _, n := range numbers {
		total += n
	}
	return float64(total) / float64(len(numbers))
}

func compute_averages(n uint, k uint, runs uint) (float64, float64) {
	steps := make([]uint, 0, runs)
	intersections := make([]uint, 0, runs)
	rand.Seed(time.Now().UnixNano())
	for i := uint(0); i < runs; i += 1 {
		w := *NewWalker(n, k)
		steps = append(steps, w.steps())
		intersections = append(intersections, w.intersections())
	}
	avg_steps := average(steps)
	avg_intersections := average(intersections)
	return avg_steps, avg_intersections
}

func main() {
	n := uint(4)
	k := uint(1000)
	runs := uint(1000000)
	steps, intersections := compute_averages(n, k, runs)
	fmt.Printf("Average of %d runs is %f steps and %f intersections\n",
		runs, steps, intersections)
}
