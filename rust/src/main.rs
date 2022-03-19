mod line;
mod bestline;
mod walker;
use crate::walker::Walker;
use rand::SeedableRng;

fn average(numbers: &[usize]) -> f64 {
	numbers.iter().sum::<usize>() as f64 / numbers.len() as f64
}

fn compute_averages(n: usize, k: usize, runs: usize) -> (f64, f64) {
	let mut steps = Vec::with_capacity(runs);
	let mut intersections = Vec::with_capacity(runs);
	let mut rng = rand::rngs::SmallRng::from_entropy();
	for _ in 0..runs {
		let w = Walker::new(&mut rng, n, k);
		steps.push(w.steps());
		intersections.push(w.intersections());
	}
	let avg_steps = average(steps.as_slice());
	let avg_intersections = average(intersections.as_slice());
	(avg_steps, avg_intersections)
}

fn main() {
	let n = 4;
	let k = 1000;
	let runs = 1000;
	let (steps, intersections) = compute_averages(n, k, runs);
	println!("Average of {} runs is {} steps and {} intersections",
			runs, steps, intersections);
}

#[cfg(test)]
mod tests {
	use super::*;
	use approx::assert_relative_eq;

    #[test]
    fn test_n_1_k_1000() {
		let (n, k, runs) = (1, 1000, 100);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 71.95, epsilon = 21.0);
		assert_relative_eq!(intersections, 11.0, epsilon = 1.6);
	}

    #[test]
    fn test_n_2_k_1000() {
		let (n, k, runs) = (2, 1000, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 71.95, epsilon = 7.0);
		assert_relative_eq!(intersections, 7.44, epsilon = 0.35);
    }

    #[test]
    fn test_n_3_k_1000() {
		let (n, k, runs) = (3, 1000, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 71.95, epsilon = 7.0);
		assert_relative_eq!(intersections, 4.57, epsilon = 0.3);
    }

    #[test]
    fn test_n_4_k_1000() {
		let (n, k, runs) = (4, 1000, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 71.95, epsilon = 7.0);
		assert_relative_eq!(intersections, 4.37, epsilon = 0.2);
    }

    #[test]
    fn test_n_5_k_1000() {
		let (n, k, runs) = (5, 1000, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 71.95, epsilon = 7.0);
		assert_relative_eq!(intersections, 3.33, epsilon = 0.2);
    }

    #[test]
    fn test_n_10_k_1() {
		let (n, k, runs) = (10, 1, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 10.98, epsilon = 0.2);
		assert_relative_eq!(intersections, 0.99, epsilon = 0.01);
    }

    #[test]
    fn test_n_1_k_10() {
		let (n, k, runs) = (1, 10, 1000);
		let (steps, intersections) = compute_averages(n, k, runs);
		assert_relative_eq!(steps, 10.98, epsilon = 0.1);
		assert_relative_eq!(intersections, 4.56, epsilon = 0.1);
    }
}
