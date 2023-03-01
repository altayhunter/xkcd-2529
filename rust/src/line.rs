#[derive(Clone, Copy, Debug, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct Point {
	x: i32,
	y: i32,
}

impl Point {
	pub fn new(x: i32, y: i32) -> Point {
		Point {x, y}
	}
	pub fn up(&self) -> Point {
		Point {x: self.x, y: self.y + 1}
	}
	pub fn right(&self) -> Point {
		Point {x: self.x + 1, y: self.y}
	}
	pub fn down(&self) -> Point {
		Point {x: self.x, y: self.y - 1}
	}
	pub fn left(&self) -> Point {
		Point {x: self.x - 1, y: self.y}
	}
	pub fn parity(&self) -> bool {
		(self.x + self.y) % 2 == 0
	}
}

impl std::fmt::Display for Point {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		write!(f, "({}, {})", self.x, self.y)
	}
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Line {
	slope: f64,
	intercept: f64,
}

impl Line {
	pub fn new(a: Point, b: Point) -> Line {
		let slope = (a.y - b.y) as f64 / (a.x - b.x) as f64;
		let intercept =
			if a.x == b.x { a.x as f64 }
			else { a.y as f64 - slope * a.x as f64 };
		Line {slope, intercept}
	}
	pub fn intersects(&self, p: Point) -> bool {
		if !self.slope.is_finite() {
			p.x as f64 == self.intercept
		} else {
			p.y as f64 == self.slope * p.x as f64 + self.intercept
		}
	}
}

impl std::fmt::Display for Line {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		if !self.slope.is_finite() {
			write!(f, "x = {}", self.intercept)
		} else {
			write!(f, "y = {}x + {}", self.slope, self.intercept)
		}
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_point_construction() {
		let origin = Point::new(0, 0);
		assert_eq!(format!("{}", origin), "(0, 0)");
		let negatives = Point::new(-5, -7);
		assert_eq!(format!("{}", negatives), "(-5, -7)");
	}

	#[test]
	fn test_point_neighbors() {
		let point = Point::new(-4, 7);
		assert_ne!(point, point.right());
		assert_eq!(point, point.left().right());
		assert_eq!(point, point.up().down());
		assert_eq!(point.up().right(), point.right().up());
	}

	#[test]
	fn test_line_no_rounding_error_symmetric() {
		let a = Point::new(1001, 1);
		let b = Point::new(-1000, -1);
		let l = Line::new(a, b);
		let c = Point::new(0, 0);
		assert!(!l.intersects(c));
		let d = Point::new(3002, 3);
		assert!(l.intersects(d));
		assert_eq!(format!("{}", l), "y = 0.0009995002498750624x + -0.0004997501249375258");
	}

	#[test]
	fn test_line_no_rounding_error_asymmetric() {
		let a = Point::new(100000, 100000);
		let b = Point::new(-1, 0);
		let l = Line::new(a, b);
		let c = Point::new(0, 1);
		assert!(!l.intersects(c));
		let d = Point::new(200001, 200000);
		assert!(l.intersects(d));
		assert_eq!(format!("{}", l), "y = 0.999990000099999x + 0.999990000098478");
	}

	#[test]
	fn test_line_largest_no_rounding_error() {
		let a = Point::new(134217726, 134217727);
		let b = Point::new(-1, 134217726);
		let l = Line::new(a, b);
		let c = Point::new(0, 134217726);
		assert!(!l.intersects(c));
		assert_eq!(format!("{}", l), "y = 0.00000000745058065243498x + 134217726.00000001");
	}

	#[test]
	fn test_line_smallest_rounding_error() {
		let a = Point::new(134217727, 134217728);
		let b = Point::new(-1, 134217727);
		let l = Line::new(a, b);
		let c = Point::new(0, 134217727);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "y = 0.000000007450580596923828x + 134217727");
	}

	#[test]
	fn test_line_vertical() {
		let a = Point::new(5, 7);
		let b = Point::new(5, 3);
		let l = Line::new(a, b);
		let c = Point::new(5, 9);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "x = 5");
	}

	#[test]
	fn test_line_horizontal() {
		let a = Point::new(7, 5);
		let b = Point::new(3, 5);
		let l = Line::new(a, b);
		let c = Point::new(9, 5);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "y = 0x + 5");
	}

	#[test]
	fn test_line_upward() {
		let a = Point::new(1, 2);
		let b = Point::new(5, 4);
		let l = Line::new(a, b);
		let c = Point::new(7, 5);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "y = 0.5x + 1.5");
	}

	#[test]
	fn test_line_downward() {
		let a = Point::new(1, 4);
		let b = Point::new(5, 2);
		let l = Line::new(a, b);
		let c = Point::new(3, 3);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "y = -0.5x + 4.5");
	}

	#[test]
	fn test_line_same_points() {
		let a = Point::new(2, -5);
		let b = Point::new(2, -5);
		let l = Line::new(a, b);
		let c = Point::new(-5, 2);
		assert!(!l.intersects(c));
		let d = Point::new(2, 7);
		assert!(l.intersects(d));
		assert_eq!(format!("{}", l), "x = 2");
	}
}
