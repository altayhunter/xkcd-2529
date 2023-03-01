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
	it('should place the first marble correctly', () => {
		const w = new Walker(4, 1);
		expect(w.marbles.length).toEqual(1);
		const hasEvenParity = p => (p.x + p.y) % 2 == 0;
		expect(hasEvenParity(w.marbles[0])).toBeTrue();
	});
	it('should behave normally', () => {
		const w = new Walker(3, 5);
		expect(w.steps()).toBeGreaterThanOrEqual(8);
		expect(w.steps()).toBeLessThanOrEqual(16);
		expect(w.intersections()).toBeGreaterThanOrEqual(2);
		expect(w.intersections()).toBeLessThanOrEqual(5);
	});
});
