use crate::bestline::BestLine;
use crate::line::Point;
use rand::Rng;
use std::collections::HashSet;

#[derive(Debug)]
pub struct Walker {
	marbles: Vec<Point>,
	visited: HashSet<Point>,
}

impl Walker {
	pub fn new(n: usize, k: usize) -> Self {
		let mut location = Point::new(0, 0);
		let mut marbles = vec![];
		let mut visited = HashSet::from([location]);
		if n == 0 || k == 0 {
			return Walker {marbles, visited};
		}
		while !Self::trapped(&visited, location) {
			let desired = Self::valid_neighbor(&visited, location);
			if visited.len() % n == 0 {
				marbles.push(desired);
			}
			visited.insert(desired);
			location = desired;
			if visited.len() > n * k {
				break;
			}
		}
		Walker {marbles, visited}
	}
	pub fn steps(&self) -> usize {
		self.visited.len()
	}
	pub fn intersections(&self) -> usize {
		BestLine::new(&self.marbles).intersections()
	}
	fn trapped(visited: &HashSet<Point>, p: Point) -> bool {
		visited.contains(&p.up()) &&
		visited.contains(&p.right()) &&
		visited.contains(&p.down()) &&
		visited.contains(&p.left())
	}
	fn valid_neighbor(visited: &HashSet<Point>, p: Point) -> Point {
		let mut neighbor = Self::random_neighbor(p);
		while visited.contains(&neighbor) {
			neighbor = Self::random_neighbor(p);
		}
		neighbor
	}
	fn random_neighbor(p: Point) -> Point {
		match rand::thread_rng().gen_range(0..4) {
			0 => p.up(),
			1 => p.right(),
			2 => p.down(),
			_ => p.left(),
		}
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_no_marbles() {
		let w = Walker::new(0, 5);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_no_steps() {
		let w = Walker::new(4, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_double_zero() {
		let w = Walker::new(0, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_normal_inputs() {
		let w = Walker::new(4, 5);
		assert!(w.steps() >= 8);
		assert!(w.steps() <= 21);
		assert!(w.intersections() >= 2);
	}
}
