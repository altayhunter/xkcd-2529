import { Walker } from '../walker.mjs';

describe('Walker', () => {
	it('should not drop marbles', () => {
		const w = new Walker(0, 5);
		expect(w.steps()).toEqual(1);
		expect(w.intersections()).toEqual(0);
	});
	it('should not take steps', () => {
		const w = new Walker(4, 0);
		expect(w.steps()).toEqual(1);
		expect(w.intersections()).toEqual(0);
	});
	it('should not drop marbles or take steps', () => {
		const w = new Walker(0, 0);
		expect(w.steps()).toEqual(1);
		expect(w.intersections()).toEqual(0);
	});
	it('should behave normally', () => {
		const w = new Walker(4, 5);
		expect(w.steps()).toBeGreaterThanOrEqual(8);
		expect(w.steps()).toBeLessThanOrEqual(21);
		expect(w.intersections()).toBeGreaterThanOrEqual(2);
	});
});
