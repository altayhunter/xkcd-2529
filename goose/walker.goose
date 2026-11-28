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

fn rotate(d: Direction.Up, n: u8) -> Direction {
	const next: Direction[4] = [
		Direction.Left, Direction.Up, Direction.Right, Direction.Down
	];
	next[n % 4]
}

fn rotate(d: Direction.Right, n: u8) -> Direction {
	const next: Direction[4] = [
		Direction.Up, Direction.Right, Direction.Down, Direction.Left
	];
	next[n % 4]
}

fn rotate(d: Direction.Down, n: u8) -> Direction {
	const next: Direction[4] = [
		Direction.Right, Direction.Down, Direction.Left, Direction.Up
	];
	next[n % 4]
}

fn rotate(d: Direction.Left, n: u8) -> Direction {
	const next: Direction[4] = [
		Direction.Down, Direction.Left, Direction.Up, Direction.Right
	];
	next[n % 4]
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
	visited.contains(p.step(Direction.Up)) &&
	visited.contains(p.step(Direction.Right)) &&
	visited.contains(p.step(Direction.Down)) &&
	visited.contains(p.step(Direction.Left))
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
	let next = d.rotate(_state.rand_range(3) as u8);
	return p.step(next), next;
}
