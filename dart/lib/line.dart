import 'point.dart';

class Line {
	final double slope;
	final double intercept;

	Line(Point a, Point b) :
		slope = (a.y - b.y) / (a.x - b.x),
		intercept = a.x == b.x ? a.x.toDouble() : a.y - (a.y - b.y) / (a.x - b.x) * a.x;

	bool intersects(Point p) {
		if (!slope.isFinite) {
			return p.x == intercept;
		} else {
			return p.y == slope * p.x + intercept;
		}
	}

	@override
	String toString() {
		if (!slope.isFinite) {
			return 'x = $intercept';
		} else {
			return 'y = ${slope}x + $intercept';
		}
	}

	@override
	bool operator ==(other) {
		return (other is Line) && other.slope == slope && other.intercept == intercept;
	}

	@override
	int get hashCode => Object.hash(slope, intercept);
}
