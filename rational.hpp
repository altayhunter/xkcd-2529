#pragma once
#include <ostream>  // ostream

class Rational {
public:
	Rational() = default;
	Rational(int n) : numerator(n) {};
	Rational(int n, int d);
	double decimal() const;
private:
	int numerator = 0;
	int denominator = 1;

	friend bool operator==(const Rational& a, const Rational& b);
	friend std::ostream& operator<<(std::ostream& out, const Rational& r);
};
