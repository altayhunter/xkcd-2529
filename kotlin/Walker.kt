class Walker(n: Int, k: Int) {
	var marbles: MutableList<Point>
	var visited: MutableSet<Point>

	init {
		var location = Point(0, 0)
		marbles = mutableListOf<Point>()
		visited = mutableSetOf<Point>(location)
		if (n != 0 && k != 0) {
			while (!trapped(location)) {
				val desired = valid_neighbor(location)
				if (visited.size % n == 0) {
					marbles.add(desired)
				}
				visited.add(desired)
				location = desired
				if (visited.size > n * k) {
					break;
				}
			}
		}
	}

	fun steps(): Int {
		return visited.size
	}

	fun intersections(): Int {
		return BestLine(marbles).intersections()
	}

	private fun trapped(p: Point): Boolean {
		return visited.contains(p.up()) &&
				visited.contains(p.right()) &&
				visited.contains(p.down()) &&
				visited.contains(p.left())
	}

	private fun valid_neighbor(p: Point): Point {
		var neighbor = random_neighbor(p)
		while (visited.contains(neighbor)) {
			neighbor = random_neighbor(p)
		}
		return neighbor
	}

	private fun random_neighbor(p: Point): Point {
		when ((0..3).random()) {
			0 -> return p.up()
			1 -> return p.right()
			2 -> return p.down()
			else -> return p.left()
		}
	}
}
