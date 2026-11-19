import std;
import walker;

struct Result {
	steps: f64,
	intersections: f64,
}

thread_fn worker(n: i64, k: i64, runs: i64) {
	var steps = 0.0;
	var intersections = 0.0;
	for _ in runs {
		let walker = create_walker(n, k);
		steps += walker.steps();
		intersections += walker.intersections();
	}
	qput(Result { steps, intersections });
}

fn compute_averages(n: i64, k: i64, runs: i64) -> f64, f64 {
	let threads = max(1, hardware_threads());
	let each = runs / threads;
	let extra = runs % threads;
	let workers: i64[>..] = [];
	for i in threads {
		if i == 0 {
			workers.push(thread_spawn(worker, n, k, each + extra));
		} else {
			workers.push(thread_spawn(worker, n, k, each));
		}
	}
	var steps = 0.0;
	var intersections = 0.0;
	for _ in workers.len {
		let result = qget<Result>();
		steps += result.steps;
		intersections += result.intersections;
	}
	for worker in workers {
		worker.thread_wait();
	}
	return steps / runs, intersections / runs;
}
