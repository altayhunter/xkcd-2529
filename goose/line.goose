import math;

struct Point {
	x: i32,
	y: i32,
}

fn step(p: Point, d: Direction.Up) -> Point {
	Point { p.x, p.y + 1 }
}

fn step(p: Point, d: Direction.Right) -> Point {
	Point { p.x + 1, p.y }
}

fn step(p: Point, d: Direction.Down) -> Point {
	Point { p.x, p.y - 1 }
}

fn step(p: Point, d: Direction.Left) -> Point {
	Point { p.x - 1, p.y }
}

fn even_parity(p: Point) -> bool {
	(p.x + p.y) % 2 == 0
}

fn hash(p: Point) -> u64 {
	hash_combine(hash(p.x), hash(p.y))
}

fn format(out: u8[>..]&, p: Point) {
	format(out, "(", p.x, ", ", p.y, ")");
}

struct Line {
	slope: f64,
	intercept: f64,
}

fn create_line(a: Point, b: Point) -> Line {
	let slope = (a.y - b.y) / (a.x - b.x) as f64;
	let intercept =
		if a.x == b.x { a.x }
		else { a.y - slope * a.x };
	Line { slope, intercept }
}

fn intersects(l: Line, p: Point) -> bool {
	if !l.slope.is_finite() {
		p.x == l.intercept
	} else {
		p.y == l.slope * p.x + l.intercept
	}
}

fn format(out: u8[>..]&, l: Line) {
	if !l.slope.is_finite() {
		format(out, "x = ", l.intercept);
	} else {
		format(out, "y = ", l.slope, "x + ", l.intercept);
	}
}
