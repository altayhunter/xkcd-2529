import java.util.ArrayList;
import java.util.HashSet;
import java.util.concurrent.ThreadLocalRandom;

public class Walker {
	ArrayList<Point> marbles = new ArrayList<>();
	HashSet<Point> visited = new HashSet<>();

	public Walker(int n, int k) {
		Point location = new Point(0, 0);
		this.visited.add(location);
		if (n == 0 || k == 0) return;
		while (!trapped(location)) {
			Point desired = validNeighbor(location);
			if (this.visited.size() % n == 0) {
				this.marbles.add(desired);
			}
			this.visited.add(desired);
			location = desired;
			if (visited.size() > n * k) break;
		}
	}

	public int intersections() {
		return (new BestLine(this.marbles)).intersections();
	}

	public int steps() {
		return this.visited.size();
	}

	private boolean trapped(Point p) {
		return this.visited.contains(p.up()) &&
				this.visited.contains(p.right()) &&
				this.visited.contains(p.down()) &&
				this.visited.contains(p.left());
	}

	private Point validNeighbor(Point p) {
		Point neighbor = randomNeighbor(p);
		while (this.visited.contains(neighbor)) {
			neighbor = randomNeighbor(p);
		}
		return neighbor;
	}

	private static Point randomNeighbor(Point p) {
		int direction = ThreadLocalRandom.current().nextInt(0, 4);
		switch (direction) {
			case 0: return p.up();
			case 1: return p.right();
			case 2: return p.down();
			default: return p.left();
		}
	}

	public static void main(String[] args) {
		int n = 4;
		int k = 1000;
		ArrayList<Integer> steps = new ArrayList<>();
		ArrayList<Integer> intersections = new ArrayList<>();
		for (int i = 0; i < 1000000; i++) {
			Walker w = new Walker(n, k);
			steps.add(w.steps());
			intersections.add(w.intersections());
		}
		double avg_steps = steps.stream().mapToInt(Integer::intValue)
				.average().orElse(Double.NaN);
		double avg_intersections = intersections.stream()
				.mapToInt(Integer::intValue).average().orElse(Double.NaN);
		System.out.println("Average of " + steps.size() + " runs is " +
				avg_steps + " steps and " + avg_intersections +
				" intersections");
	}
}
