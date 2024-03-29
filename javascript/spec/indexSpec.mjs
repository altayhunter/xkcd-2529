import { compute_averages } from '../index.mjs';

describe('index', () => {
	it('has n=1 k=1000', async () => {
		const [n, k, runs] = [1, 1000, 100];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 71.95)).toBeLessThan(17.5);
		expect(Math.abs(intersections - 11.0)).toBeLessThan(1.6);
	});
	it('has n=2 k=1000', async () => {
		const [n, k, runs] = [2, 1000, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 71.95)).toBeLessThan(7.0);
		expect(Math.abs(intersections - 7.44)).toBeLessThan(0.35);
	});
	it('has n=3 k=1000', async () => {
		const [n, k, runs] = [3, 1000, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 71.95)).toBeLessThan(7.0);
		expect(Math.abs(intersections - 4.57)).toBeLessThan(0.3);
	});
	it('has n=4 k=1000', async () => {
		const [n, k, runs] = [4, 1000, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 71.95)).toBeLessThan(7.0);
		expect(Math.abs(intersections - 4.37)).toBeLessThan(0.2);
	});
	it('has n=5 k=1000', async () => {
		const [n, k, runs] = [5, 1000, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 71.95)).toBeLessThan(7.0);
		expect(Math.abs(intersections - 3.33)).toBeLessThan(0.2);
	});
	it('has n=10 k=1', async () => {
		const [n, k, runs] = [10, 1, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 10.98)).toBeLessThan(0.2);
		expect(Math.abs(intersections - 0.99)).toBeLessThan(0.01);
	});
	it('has n=1 k=10', async () => {
		const [n, k, runs] = [1, 10, 1000];
		const [steps, intersections] = await compute_averages(n, k, runs);
		expect(Math.abs(steps - 10.98)).toBeLessThan(0.1);
		expect(Math.abs(intersections - 4.56)).toBeLessThan(0.1);
	});
});
