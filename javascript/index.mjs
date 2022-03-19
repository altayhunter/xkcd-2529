import { Walker } from './walker.mjs';
import { isMain } from './util.mjs';

function average(array) {
	return array.reduce((a, n) => a + n) / array.length;
}

function compute_averages(n, k, runs) {
	const steps = [];
	const intersections = [];
	for (let i = 0; i < runs; i++) {
		const w = new Walker(n, k);
		steps.push(w.steps());
		intersections.push(w.intersections());
	}
	const avg_steps = average(steps);
	const avg_intersections = average(intersections);
	return [avg_steps, avg_intersections];
}

if (isMain(import.meta.url)) {
	const n = 4;
	const k = 1000;
	const runs = 1000000;
	const [steps, intersections] = compute_averages(n, k, runs);
	console.log(`Average of ${runs} runs is ${steps} steps and ` +
			`${intersections} intersections`);
}

export {
	compute_averages,
};
