fun compute_averages(n: Int, k: Int, runs: Int): Pair<Double, Double> {
	val steps = mutableListOf<Int>()
	val intersections = mutableListOf<Int>()
	repeat(runs) {
		val w = Walker(n, k)
		steps.add(w.steps())
		intersections.add(w.intersections())
	}
	return Pair(steps.average(), intersections.average())
}

fun main() {
	val n = 4
	val k = 1000
	val runs = 1000000
	val (steps, intersections) = compute_averages(n, k, runs)
	println("Average of ${runs} runs is ${steps} steps and " +
			"${intersections} intersections")
}
