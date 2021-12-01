use num::integer::gcd;

#[derive(Clone, Copy, Debug, Eq, Hash, Ord, PartialEq, PartialOrd)]
pub struct Rational {
	numerator: i64,
	denominator: i64,
}

impl Rational {
	pub fn new(mut n: i64, mut d: i64) -> Rational {
		if d < 0 {
			n = -n;
			d = -d;
		} else if d == 0 {
			n = 1;
		}
		let divisor = gcd(n, d);
		let numerator = n / divisor;
		let denominator = d / divisor;
		Rational {numerator, denominator}
	}
}

impl std::fmt::Display for Rational {
	fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
		if self.denominator == 1 {
			write!(f, "{}", self.numerator)
		} else {
			write!(f, "{}/{}", self.numerator, self.denominator)
		}
	}
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_reduce() {
		let a = Rational::new(30, -70);
		let b = Rational::new(-45, 105);
		assert_eq!(a, b);
	}

    #[test]
    fn test_integer() {
		let a = Rational::new(3, 1);
		let b = Rational::new(6, 2);
		let c = Rational::new(9, 1);
		assert_eq!(a, b);
		assert_ne!(a, c);
	}

    #[test]
    fn test_negative_denominator() {
		let a = Rational::new(5, -7);
		let b = Rational::new(-5, 7);
		let c = Rational::new(5, 7);
		assert_eq!(a, b);
		assert_ne!(a, c);
	}

    #[test]
    fn test_double_negative() {
		let a = Rational::new(-5, -7);
		let b = Rational::new(5, 7);
		let c = Rational::new(-5, 7);
		assert_eq!(a, b);
		assert_ne!(a, c);
	}

    #[test]
    fn test_zero_numerator() {
		let a = Rational::new(0, -7);
		let b = Rational::new(0, 3);
		let c = Rational::new(1, -7);
		assert_eq!(a, b);
		assert_ne!(a, c);
	}

    #[test]
    fn test_zero_denominator() {
		let a = Rational::new(-3, 0);
		let b = Rational::new(7, 0);
		let c = Rational::new(-3, 1);
		assert_eq!(a, b);
		assert_ne!(a, c);
	}
}
