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

func main() {
	n := uint(4)
	k := uint(1000)
	steps := []uint{}
	intersections := []uint{}
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 1000000; i += 1 {
		w := *NewWalker(n, k)
		steps = append(steps, w.steps())
		intersections = append(intersections, w.intersections())
	}
	avg_steps := average(steps)
	avg_intersections := average(intersections)
	fmt.Printf("Average of %d runs is %f steps and %f intersections\n",
		len(steps), avg_steps, avg_intersections)
}
