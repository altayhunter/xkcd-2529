data class Point(val x: Int, val y: Int) {
	override fun toString(): String {
		return "($x, $y)"
	}

	fun up(): Point {
		return Point(x, y + 1)
	}

	fun right(): Point {
		return Point(x + 1, y)
	}

	fun down(): Point {
		return Point(x, y - 1)
	}

	fun left(): Point {
		return Point(x - 1, y)
	}
}
