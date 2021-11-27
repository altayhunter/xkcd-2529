use num_rational::Rational64;

#[derive(Clone, Copy, Debug, Eq, Hash, PartialEq)]
pub struct Point {
	x: i64,
	y: i64,
}

impl Point {
	pub fn new(x: i64, y: i64) -> Point {
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
}

impl std::fmt::Display for Point {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		write!(f, "({}, {})", self.x, self.y)
	}
}

#[derive(Clone, Copy, Debug, Eq, Hash, PartialEq)]
pub struct Line {
	point: Point,
	slope: Option<Rational64>,
}

impl Line {
	pub fn new(a: Point, b: Point) -> Line {
		let delta_x = a.x - b.x;
		let delta_y = a.y - b.y;
		let slope =
			if delta_x == 0 {
				None
			} else {
				Some(Rational64::new(delta_y, delta_x))
			};
		Line {point: a, slope: slope}
	}
	pub fn intersects(&self, p: Point) -> bool {
		let delta_x = p.x - self.point.x;
		let delta_y = p.y - self.point.y;
		if self.slope == None {
			self.point.x == p.x
		} else if delta_x == 0 {
			false
		} else {
			self.slope.unwrap() == Rational64::new(delta_y, delta_x)
		}
	}
}

impl std::fmt::Display for Line {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		write!(f, "{} {}", self.point,
			if self.slope == None {
				String::from("1/0")
			} else {
				self.slope.unwrap().to_string()
			}
		)
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_rational() {
		let a = Rational64::new(30, -70);
		let b = Rational64::new(-45, 105);
		assert_eq!(format!("{}", a), "-3/7");
		assert_eq!(a, b);
	}

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
	fn test_line_vertical() {
		let a = Point::new(5, 7);
		let b = Point::new(5, 3);
		let l = Line::new(a, b);
		let c = Point::new(5, 9);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "(5, 7) 1/0");
	}

	#[test]
	fn test_line_horizontal() {
		let a = Point::new(7, 5);
		let b = Point::new(3, 5);
		let l = Line::new(a, b);
		let c = Point::new(9, 5);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "(7, 5) 0");
	}

	#[test]
	fn test_line_upward() {
		let a = Point::new(1, 2);
		let b = Point::new(5, 4);
		let l = Line::new(a, b);
		let c = Point::new(7, 5);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "(1, 2) 1/2");
	}

	#[test]
	fn test_line_downward() {
		let a = Point::new(1, 4);
		let b = Point::new(5, 2);
		let l = Line::new(a, b);
		let c = Point::new(3, 3);
		assert!(l.intersects(c));
		assert_eq!(format!("{}", l), "(1, 4) -1/2");
	}

	#[test]
	fn test_line_same_points() {
		let a = Point::new(0, 0);
		let b = Point::new(0, 0);
		let l = Line::new(a, b);
		let c = Point::new(0, 7);
		assert!(l.intersects(c));
		let d = Point::new(7, 0);
		assert!(!l.intersects(d));
		assert_eq!(format!("{}", l), "(0, 0) 1/0");
	}
}
