use crate::line::Point;
use crate::line::Line;

#[derive(PartialEq, Eq, Clone, Copy, Debug)]
pub struct BestLine {
	points: usize,
	best_fit: Line,
}

impl BestLine {
	pub fn new(points: &[Point]) -> BestLine {
		if points.len() < 2 {
			let zero = Point::new(0, 0);
			return BestLine {
				points: points.len(),
				best_fit: Line::new(zero, zero),
			};
		}
		let mut max_i = 0;
		let mut max_l = Line::new(points[0], points[1]);
		for i in 0..points.len() {
			for j in i+1..points.len() {
				let a = points[i];
				let b = points[j];
				let l = Line::new(a, b);
				let intersections = 2 + points[j+1..].iter().filter(|&p| l.intersects(*p)).count();
				if intersections > max_i {
					max_i = intersections;
					max_l = l;
				}
			}
		}
		BestLine {points: max_i, best_fit: max_l}
	}
	pub fn intersections(&self) -> usize {
		self.points
	}
}

impl std::fmt::Display for BestLine {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		write!(f, "{}", self.best_fit)
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_four_horizontal_three_vertical() {
		let v = vec![
			Point::new(0, 1),
			Point::new(1, 1),
			Point::new(1, 0),
			Point::new(2, 1),
			Point::new(1, 2),
			Point::new(3, 1),
		];
		let bl = BestLine::new(&v);
		assert_eq!(format!("{}", bl), "(0, 1) 0");
		assert_eq!(bl.points, 4);
	}

	#[test]
	fn test_three_diagonal_two_horizontal() {
		let v = vec![
			Point::new(3, 3),
			Point::new(5, 3),
			Point::new(2, 0),
			Point::new(4, 6),
		];
		let bl = BestLine::new(&v);
		assert_eq!(format!("{}", bl), "(3, 3) 3");
		assert_eq!(bl.points, 3);
	}
}
