class Line(a: Point, b: Point) {
	val slope: Double
	val intercept: Double

	init {
		slope = (a.y - b.y).toDouble() / (a.x - b.x)
		intercept = if (a.x == b.x) a.x.toDouble() else a.y - slope * a.x
	}

	fun intersects(p: Point): Boolean {
		if (!slope.isFinite()) return p.x.toDouble() == intercept
		return p.y.toDouble() == slope * p.x + intercept
	}

	override fun toString(): String {
		if (!slope.isFinite()) return "x = $intercept"
		return "y = ${slope}x + $intercept"
	}
}
