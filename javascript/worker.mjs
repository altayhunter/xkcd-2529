import { Walker } from './walker.mjs';
import {
	parentPort,
	workerData,
} from 'worker_threads';

let steps = 0;
let intersections = 0;
for (let i = 0; i < workerData.runs; i++) {
	const w = new Walker(workerData.n, workerData.k);
	steps += w.steps();
	intersections += w.intersections();
}
parentPort.postMessage({steps, intersections});