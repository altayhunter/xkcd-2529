mod line;
mod bestline;
mod walker;
use crate::walker::Walker;

fn average(numbers: &[usize]) -> f64 {
	numbers.iter().sum::<usize>() as f64 / numbers.len() as f64
}

fn main() {
	let n = 4;
	let k = 1000;
	let mut steps = vec![];
	let mut intersections = vec![];
	for _ in 0..1000000 {
		let w = Walker::new(n, k);
		steps.push(w.steps());
		intersections.push(w.intersections());
	}
	let avg_steps = average(steps.as_slice());
	let avg_intersections = average(intersections.as_slice());
	println!("Average of {} runs is {} steps and {} intersections",
			steps.len(), avg_steps, avg_intersections);
}
