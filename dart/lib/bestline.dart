import 'line.dart';
import 'point.dart';

class BestLine {
	int points;
	Line bestFit;

	BestLine(List<Point> points) :
			points = points.length,
			bestFit = Line(Point(0, 0), Point(0, 0)) {
		if (points.length > 1) {
			int maxI = 0;
			var maxL = Line(points[0], points[1]);
			for (int i = 0; i < points.length - 1; i += 1) {
				for (int j = i + 1; j < points.length; j += 1) {
					final a = points[i];
					final b = points[j];
					final l = Line(a, b);
					final intersections = 2 + points.sublist(j + 1)
							.where((p) => l.intersects(p)).length;
					if (intersections > maxI) {
						maxI = intersections;
						maxL = l;
					}
				}
			}
			this.points = maxI;
			bestFit = maxL;
		}
	}

	@override
	String toString() {
		return bestFit.toString();
	}
}
