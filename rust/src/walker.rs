use crate::bestline::BestLine;
use crate::line::Point;
use rand::Rng;
use rand::rngs::SmallRng;
use std::collections::HashSet;
#[cfg(not(test))]
use log::debug;
#[cfg(test)]
use std::{println as debug};

#[derive(Debug)]
pub struct Walker {
	marbles: Vec<Point>,
	visited: HashSet<Point>,
}

#[derive(Clone, Copy, Debug)]
enum Direction {
	Up,
	Right,
	Down,
	Left,
}

impl Walker {
	pub fn new(rng: &mut SmallRng, n: usize, k: usize) -> Self {
		let mut location = Point::new(0, 0);
		let mut marbles = vec![];
		let mut visited = HashSet::from([location]);
		if n == 0 || k == 0 {
			return Walker {marbles, visited};
		}
		let mut direction;
		(location, direction) = Self::first_random_neighbor(rng, location);
		visited.insert(location);
		debug!("Moved {:?} to {}", direction, location);
		if n == 1 {
			marbles.push(location);
			if k == 1 { return Walker {marbles, visited}; }
		}
		while !Self::trapped(&visited, location) {
			(location, direction) =
					Self::valid_neighbor(rng, &visited, location, direction);
			visited.insert(location);
			debug!("Moved {:?} to {}", direction, location);
			if visited.len() % n == 0 {
				marbles.push(location);
			}
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
	fn valid_neighbor(
			rng: &mut SmallRng,
			visited: &HashSet<Point>,
			p: Point,
			d: Direction) -> (Point, Direction) {
		let mut neighbor = Self::random_neighbor(rng, p, d);
		while visited.contains(&neighbor.0) {
			neighbor = Self::random_neighbor(rng, p, d);
		}
		neighbor
	}
	fn first_random_neighbor(rng: &mut SmallRng, p: Point) -> (Point, Direction) {
		match rng.gen_range(0..4) {
			0 => (p.up(), Direction::Up),
			1 => (p.right(), Direction::Right),
			2 => (p.down(), Direction::Down),
			_ => (p.left(), Direction::Left),
		}
	}
	fn random_neighbor(rng: &mut SmallRng, p: Point, d: Direction)
			-> (Point, Direction) {
		match d {
			Direction::Up => match rng.gen_range(0..3) {
				0 => (p.left(), Direction::Left),
				1 => (p.up(), Direction::Up),
				_ => (p.right(), Direction::Right),
			},
			Direction::Right => match rng.gen_range(0..3) {
				0 => (p.up(), Direction::Up),
				1 => (p.right(), Direction::Right),
				_ => (p.down(), Direction::Down),
			},
			Direction::Down => match rng.gen_range(0..3) {
				0 => (p.right(), Direction::Right),
				1 => (p.down(), Direction::Down),
				_ => (p.left(), Direction::Left),
			},
			Direction::Left => match rng.gen_range(0..3) {
				0 => (p.down(), Direction::Down),
				1 => (p.left(), Direction::Left),
				_ => (p.up(), Direction::Up),
			},
		}
	}
}

#[cfg(test)]
mod tests {
	use super::*;
	use rand::SeedableRng;

	#[test]
	fn test_no_marbles() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 0, 5);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_no_steps() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 4, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_double_zero() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 0, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_normal_inputs() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 3, 5);
		assert!(w.steps() >= 8);
		assert!(w.steps() <= 21);
		assert!(w.intersections() >= 2);
	}
}
