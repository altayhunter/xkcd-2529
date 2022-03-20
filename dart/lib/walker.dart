import 'point.dart';
import 'bestline.dart';
import 'dart:collection';
import 'dart:math';

bool trapped(HashSet<Point> visited, Point p) {
	return visited.contains(p.up()) &&
			visited.contains(p.right()) &&
			visited.contains(p.down()) &&
			visited.contains(p.left());
}

Point validNeighbor(Random rng, HashSet<Point> visited, Point p) {
	var neighbor = randomNeighbor(rng, p);
	while (visited.contains(neighbor)) {
		neighbor = randomNeighbor(rng, p);
	}
	return neighbor;
}

Point randomNeighbor(Random rng, Point p) {
	switch (rng.nextInt(4)) {
		case 0: return p.up();
		case 1: return p.right();
		case 2: return p.down();
		default: return p.left();
	}
}

class Walker {
	final marbles = <Point>[];
	final visited = HashSet<Point>.of({Point(0, 0)});

	Walker(Random rng, int n, int k) {
		if (n == 0 || k == 0) return;
		var location = visited.first;
		while (!trapped(visited, location)) {
			final desired = validNeighbor(rng, visited, location);
			if (visited.length % n == 0) {
				marbles.add(desired);
			}
			visited.add(desired);
			location = desired;
			if (visited.length > n * k) {
				break;
			}
		}
	}

	int steps() {
		return visited.length;
	}

	int intersections() {
		return BestLine(marbles).points;
	}
}
