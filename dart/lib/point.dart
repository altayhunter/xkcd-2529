class Point {
	final int x;
	final int y;

	Point(this.x, this.y);

	Point up() {
		return Point(x, y + 1);
	}

	Point right() {
		return Point(x + 1, y);
	}

	Point down() {
		return Point(x, y - 1);
	}

	Point left() {
		return Point(x - 1, y);
	}

	@override
	String toString() {
		return '($x, $y)';
	}

	@override
	bool operator ==(other) {
		return (other is Point) && other.x == x && other.y == y;
	}

	@override
	int get hashCode => Object.hash(x, y);
}
