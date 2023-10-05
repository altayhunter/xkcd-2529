package main

import "hash/maphash"

type Walker struct {
	marbles []Point
	visited map[Point]bool
}

func NewWalker(n uint, k uint) *Walker {
	location := Point{0, 0}
	marbles := []Point{}
	visited := map[Point]bool{location: true}
	if n == 0 || k == 0 {
		return &Walker{marbles, visited}
	}
	for !trapped(visited, location) {
		desired := valid_neighbor(visited, location)
		if uint(len(visited))%n == 0 {
			marbles = append(marbles, desired)
		}
		visited[desired] = true
		location = desired
		if uint(len(visited)) > n*k {
			break
		}
	}
	return &Walker{marbles, visited}
}

func (w Walker) steps() uint {
	return uint(len(w.visited))
}

func (w Walker) intersections() uint {
	return NewBestLine(w.marbles).intersections()
}

func trapped(visited map[Point]bool, p Point) bool {
	return visited[p.up()] && visited[p.right()] &&
		visited[p.down()] && visited[p.left()]
}

func valid_neighbor(visited map[Point]bool, p Point) Point {
	neighbor := random_neighbor(p)
	for visited[neighbor] {
		neighbor = random_neighbor(p)
	}
	return neighbor
}

func random_neighbor(p Point) Point {
	switch rand(4) {
	case 0:
		return p.up()
	case 1:
		return p.right()
	case 2:
		return p.down()
	default:
		return p.left()
	}
}

func rand(max uint64) uint64 {
	return new(maphash.Hash).Sum64() % max
}
