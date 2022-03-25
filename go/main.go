package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"time"
	"github.com/barweiss/go-tuple"
)

func worker(done chan tuple.T2[uint, uint], n uint, k uint, runs uint) {
	steps := uint(0)
	intersections := uint(0)
	for i := uint(0); i < runs; i += 1 {
		w := *NewWalker(n, k)
		steps += w.steps()
		intersections += w.intersections()
	}
	done <- tuple.New2(steps, intersections)
}

func compute_averages(n uint, k uint, runs uint) (float64, float64) {
	threads := uint(runtime.NumCPU())
	done := make(chan tuple.T2[uint, uint], threads)
	rand.Seed(time.Now().UnixNano())
	for i := uint(0); i < threads; i += 1 {
		each := runs / threads
		extra := runs % threads
		if i == 0 {
			go worker(done, n, k, each + extra)
		} else {
			go worker(done, n, k, each)
		}
	}
	steps, intersections := uint(0), uint(0)
	for i := uint(0); i < threads; i += 1 {
		values := <- done
		steps += values.V1
		intersections += values.V2
	}
	avg_steps := float64(steps) / float64(runs)
	avg_intersections := float64(intersections) / float64(runs)
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
