public class Line {
	double slope;
	double intercept;

	public Line(Point a, Point b) {
		this.slope = (double)(a.y - b.y) / (a.x - b.x);
		this.intercept = a.x == b.x ? a.x : a.y - this.slope * a.x;
	}

	public boolean intersects(Point p) {
		if (Double.isInfinite(this.slope)) {
			return p.x == this.intercept;
		}
		return p.y == this.slope * p.x + this.intercept;
	}

	@Override
	public String toString() {
		if (Double.isInfinite(this.slope)) {
			return "x = " + this.intercept;
		}
		return "y = " + this.slope + "x + " + this.intercept;
	}
}
