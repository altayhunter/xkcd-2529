import bestline;
import dictionary;
import line;
import os;

let _state = rng { s: random_seed() };

enum Direction {
	Up,
	Right,
	Down,
	Left,
}

struct Walker {
	marbles: Point[],
	visited: dictionary<Point, bool>,
}

fn create_walker(n: i64, k: i64) -> Walker {
	var marbles: Point[>..] = [];
	var visited = dictionary<Point, bool> {};
	visited.insert(Point { 0, 0 }, true);
	if n == 0 || k == 0 {
		return Walker { marbles, visited };
	}
	var location = Point { 0, 1 };
	visited.insert(location, true);
	var direction = Direction.Up;
	if n == 1 {
		marbles.push(location);
		if k == 1 { return Walker { marbles, visited }; }
	}
	while !trapped(visited, location) {
		location, direction = valid_neighbor(visited, location, direction);
		visited.insert(location, true);
		if (visited.count - 1) % n == 0 {
			marbles.push(location);
		}
		if visited.count > n * k {
			break;
		}
	}
	Walker { marbles, visited }
}

fn steps(w: const Walker&) -> i64 {
	w.visited.count
}

fn intersections(w: const Walker&) -> i64 {
	create_best_line(w.marbles).points
}

fn trapped(visited: const dictionary<Point, bool>&, p: Point) -> bool {
	visited.contains(p.up()) &&
	visited.contains(p.right()) &&
	visited.contains(p.down()) &&
	visited.contains(p.left())
}

fn valid_neighbor(
		visited: const dictionary<Point, bool>&,
		p: Point,
		d: Direction) -> Point, Direction {
	var np, nd = random_neighbor(p, d);
	while visited.contains(np) {
		np, nd = random_neighbor(p, d);
	}
	return np, nd;
}

fn random_neighbor(p: Point, d: Direction) -> Point, Direction {
	match d {
		Up => match _state.rand_range(3) {
			0 => { return p.left(), Direction.Left; },
			1 => { return p.up(), Direction.Up; },
			_ => { return p.right(), Direction.Right; },
		},
		Right => match _state.rand_range(3) {
			0 => { return p.up(), Direction.Up; },
			1 => { return p.right(), Direction.Right; },
			_ => { return p.down(), Direction.Down; },
		},
		Down => match _state.rand_range(3) {
			0 => { return p.right(), Direction.Right; },
			1 => { return p.down(), Direction.Down; },
			_ => { return p.left(), Direction.Left; },
		},
		Left => match _state.rand_range(3) {
			0 => { return p.down(), Direction.Down; },
			1 => { return p.left(), Direction.Left; },
			_ => { return p.up(), Direction.Up; },
		},
	}
}
