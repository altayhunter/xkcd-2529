use crate::bestline::BestLine;
use crate::line::Point;
use rand::Rng;
use rand::rngs::SmallRng;
use rustc_hash::FxHashSet;

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Direction {
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3,
}

impl Direction {
	fn rotate(self, n: u8) -> Self {
		let previous = self as u8 + 3;
		match previous.wrapping_add(n) % 4 {
			0 => Direction::Up,
			1 => Direction::Right,
			2 => Direction::Down,
			_ => Direction::Left,
		}
	}
}

#[derive(Debug)]
pub struct Walker {
	marbles: Vec<Point>,
	visited: FxHashSet<Point>,
}

impl Walker {
	pub fn new(rng: &mut SmallRng, n: usize, k: usize) -> Self {
		let mut marbles = vec![];
		let mut visited = FxHashSet::default();
		visited.insert(Point::new(0, 0));
		if n == 0 || k == 0 {
			return Walker {marbles, visited};
		}
		let mut location = Point::new(0, 1);
		visited.insert(location);
		let mut direction = Direction::Up;
		if n == 1 {
			marbles.push(location);
			if k == 1 { return Walker {marbles, visited}; }
		}
		while !Self::trapped(&visited, location) {
			(location, direction) =
					Self::valid_neighbor(rng, &visited, location, direction);
			visited.insert(location);
			if (visited.len() - 1) % n == 0 {
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
	fn trapped(visited: &FxHashSet<Point>, p: Point) -> bool {
		visited.contains(&p.step(Direction::Up)) &&
		visited.contains(&p.step(Direction::Right)) &&
		visited.contains(&p.step(Direction::Down)) &&
		visited.contains(&p.step(Direction::Left))
	}
	fn valid_neighbor(
			rng: &mut SmallRng,
			visited: &FxHashSet<Point>,
			p: Point,
			d: Direction) -> (Point, Direction) {
		let mut neighbor = Self::random_neighbor(rng, p, d);
		while visited.contains(&neighbor.0) {
			neighbor = Self::random_neighbor(rng, p, d);
		}
		neighbor
	}
	fn random_neighbor(rng: &mut SmallRng, p: Point, d: Direction)
			-> (Point, Direction) {
		let next = d.rotate(rng.gen_range(0..3));
		(p.step(next), next)
	}
}

#[cfg(test)]
mod tests {
	use super::*;
	use rand::SeedableRng;

	#[test]
	fn test_direction_rotate() {
		let d = Direction::Left;
		assert_eq!(d.rotate(0), Direction::Down);
		assert_eq!(d.rotate(1), Direction::Left);
		assert_eq!(d.rotate(2), Direction::Up);
		assert_eq!(d.rotate(3), Direction::Right);
		assert_eq!(d.rotate(255), d.rotate(3));
	}

	#[test]
	fn test_walker_no_marbles() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 0, 5);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_walker_no_steps() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 4, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_walker_double_zero() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 0, 0);
		assert_eq!(w.steps(), 1);
		assert_eq!(w.intersections(), 0);
	}

	#[test]
	fn test_walker_marble_placement() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 4, 1);
		assert_eq!(w.marbles.len(), 1);
		assert_eq!(w.marbles[0].even_parity(), true);
	}

	#[test]
	fn test_walker_normal_inputs() {
		let mut rng = rand::rngs::SmallRng::from_entropy();
		let w = Walker::new(&mut rng, 3, 5);
		assert!(w.steps() >= 8);
		assert!(w.steps() <= 16);
		assert!(w.intersections() >= 2);
		assert!(w.intersections() <= 5);
	}
}
