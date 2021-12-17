import { Walker } from './walker.mjs';

const n = 4;
const k = 1000;
const steps = [];
const intersections = [];
for (let i = 0; i < 1000000; i++) {
	const w = new Walker(n, k);
	steps.push(w.steps());
	intersections.push(w.intersections());
}
const avg_steps = steps.reduce((a, n) => a + n) / steps.length;
const avg_intersections = intersections.reduce((a, n) => a + n) / intersections.length;
console.log(`Average of ${steps.length} runs is ${avg_steps} steps and ${avg_intersections} intersections`);
