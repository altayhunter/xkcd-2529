import { isMain } from './util.mjs';
import * as os from 'os';
import { Worker } from 'worker_threads';

async function create_worker(n, k, runs) {
	return new Promise((resolve, reject) => {
		const worker = new Worker('./worker.mjs', {
			workerData: { n, k, runs }
		});
		worker.on('message', msg => resolve(msg));
		worker.on('error', err => reject(err));
		worker.on('exit', code => {
			if (!code) reject(new Error(
				`Worker exited with code ${code}!`
			));
		});
	});
}

async function compute_averages(n, k, runs) {
	const cores = os.cpus().length;
	const each = Math.floor(runs / cores);
	const extra = runs % cores;
	const workers = new Set();
	workers.add(create_worker(n, k, each + extra));
	for (let i = 0; i < cores - 1; i++) {
		workers.add(create_worker(n, k, each));
	}
	let steps = 0;
	let intersections = 0;
	for (const worker of workers) {
		const result = await worker;
		steps += result.steps;
		intersections += result.intersections;
	}
	return [steps / runs, intersections / runs];
}

if (isMain(import.meta.url)) {
	const n = 4;
	const k = 1000;
	const runs = 1000000;
	const [steps, intersections] = await compute_averages(n, k, runs);
	console.log(`Average of ${runs} runs is ${steps} steps and ` +
			`${intersections} intersections`);
}

export {
	compute_averages,
};
