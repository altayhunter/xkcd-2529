public class Point {
	int x;
	int y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public Point up() {
		return new Point(this.x, this.y + 1);
	}

	public Point right() {
		return new Point(this.x + 1, this.y);
	}

	public Point down() {
		return new Point(this.x, this.y - 1);
	}

	public Point left() {
		return new Point(this.x - 1, this.y);
	}

	@Override
	public boolean equals(Object o) {
		if (o == this) return true;
		if (o == null) return false;
		if (o.getClass() != getClass()) return false;
		Point p = (Point)o;
		return p.x == this.x && p.y == this.y;
	}

	@Override
	public int hashCode() {
		return (this.y << 16) ^ this.x;
	}

	@Override
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}
