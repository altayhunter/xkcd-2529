import kotlinx.coroutines.*

fun worker(n: Int, k: Int, runs: Int): Pair<Double, Double> {
	var steps = 0
	var intersections = 0
	repeat(runs) {
		val w = Walker(n, k)
		steps += w.steps()
		intersections += w.intersections()
	}
	val div = runs.toDouble()
	return Pair(steps / div, intersections / div)
}

suspend fun compute_averages(n: Int, k: Int, runs: Int): Pair<Double, Double> {
	val threads = Runtime.getRuntime().availableProcessors()
	assert(runs % threads == 0)
	val results = coroutineScope {
		List(threads) { async { worker(n, k, runs / threads) } }.awaitAll()
    }
	val (steps, intersections) = results.unzip()
	return Pair(steps.average(), intersections.average())
}

suspend fun main() {
	val n = 4
	val k = 1000
	val runs = 1_000_000
	val (steps, intersections) = compute_averages(n, k, runs)
	println("Average of ${runs} runs is ${steps} steps and " +
			"${intersections} intersections")
}
