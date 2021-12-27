import java.util.ArrayList;

public class BestLine {
	int points;
	Line best_fit;

	public BestLine(ArrayList<Point> points) {
		if (points.size() < 2) {
			this.points = points.size();
			return;
		}
		for (int i = 0; i < points.size() - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				Point a = points.get(i);
				Point b = points.get(j);
				Line l = new Line(a, b);
				int intersections = 2 + (int)points.subList(j + 1, points.size()).
						stream().filter(p -> l.intersects(p)).count();
				if (intersections > this.points) {
					this.points = intersections;
					this.best_fit = l;
				}
			}
		}
	}

	public int intersections() {
		return points;
	}
}
