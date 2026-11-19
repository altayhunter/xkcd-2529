import workers;

fn main() {
	let n = 4;
	let k = 1000;
	let runs = 1000000;
	let steps, intersections = compute_averages(n, k, runs);
	print(
		"Average of ", runs, " runs is ", steps, " steps and ",
		intersections, " intersections."
	);
}
