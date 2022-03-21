class BestLine(points: MutableList<Point>) {
	var numPoints: Int = 0

	init {
		if (points.size < 2) {
			numPoints = points.size
		} else {
			for (i in 0 until points.size - 1) {
				for (j in i + 1 until points.size) {
					val a = points[i]
					val b = points[j]
					val l = Line(a, b)
					val intersections = 2 + points.subList(j + 1, points.size).
							count{l.intersects(it)}
					if (intersections > numPoints) {
						numPoints = intersections
					}
				}
			}
		}
	}

	fun intersections(): Int {
		return numPoints
	}
}
