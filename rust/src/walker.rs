use crate::bestline::BestLine;
use crate::line::Point;
use rand::Rng;
use rand::rngs::SmallRng;
use std::collections::HashSet;

#[derive(Debug)]
pub struct Walker {
	marbles: Vec<Point>,
	visited: HashSet<Point>,
}

impl Walker {
	pub fn new(rng: &mut SmallRng, n: usize, k: usize) -> Self {
		let mut location = Point::new(0, 0);
		let mut marbles = vec![];
		let mut visited = HashSet::from([location]);
		if n == 0 || k == 0 {
			return Walker {marbles, visited};
		}
		while !Self::trapped(&visited, location) {
			let desired = Self::valid_neighbor(rng, &visited, location);
			if visited.len() % n == 0 {
				marbles.push(desired);
			}
			visited.insert(desired);
			location = desired;
			log::debug!("Visited {}", location);
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
	fn valid_neighbor(rng: &mut SmallRng, visited: &HashSet<Point>, p: Point) -> Point {
		let mut neighbor = Self::random_neighbor(rng, p);
		while visited.contains(&neighbor) {
			neighbor = Self::random_neighbor(rng, p);
		}
		neighbor
	}
	fn random_neighbor(rng: &mut SmallRng, p: Point) -> Point {
		match rng.gen_range(0..4) {
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
