#include "rational.hpp" // Rational
#include <numeric>      // gcd

Rational::Rational(int n, int d) {
	if (d < 0) {
		n = -n;
		d = -d;
	} else if (d == 0) {
		n = 1;
	}
	int divisor = std::gcd(n, d);
	numerator = n / divisor;
	denominator = d / divisor;
}

double Rational::decimal() const {
	return static_cast<double>(numerator)/denominator;
}

bool operator==(const Rational& a, const Rational& b) {
	return a.numerator == b.numerator && a.denominator == b.denominator;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
	if (r.denominator == 1) {
		return out << r.numerator;
	}
	return out << r.numerator << "/" << r.denominator;
}
