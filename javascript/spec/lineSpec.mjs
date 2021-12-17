import { Point } from '../point.mjs';
import { Line } from '../line.mjs';

describe('Line', () => {
	it('should not have rounding errors in symmetric case', () => {
		const a = new Point(1001, 1);
		const b = new Point(-1000, -1);
		const l = new Line(a, b);
		const c = new Point(0, 0);
		expect(l.intersects(c)).toBeFalse();
		const d = new Point(3002, 3);
		expect(l.intersects(d)).toBeTrue();
		expect(l.toString()).toEqual("y = 0.0009995002498750624x + -0.0004997501249375258");
	});
	it('should not have rounding errors in asymmetric case', () => {
		const a = new Point(100000, 100000);
		const b = new Point(-1, 0);
		const l = new Line(a, b);
		const c = new Point(0, 1);
		expect(l.intersects(c)).toBeFalse();
		const d = new Point(200001, 200000);
		expect(l.intersects(d)).toBeTrue();
		expect(l.toString()).toEqual("y = 0.999990000099999x + 0.999990000098478");
	});
	it('should not have rounding error up to this point', () => {
		const a = new Point(134217726, 134217727);
		const b = new Point(-1, 134217726);
		const l = new Line(a, b);
		const c = new Point(0, 134217726);
		expect(l.intersects(c)).toBeFalse();
		expect(l.toString()).toEqual("y = 7.45058065243498e-9x + 134217726.00000001");
	});
	it('should have rounding error past this point', () => {
		const a = new Point(134217727, 134217728);
		const b = new Point(-1, 134217727);
		const l = new Line(a, b);
		const c = new Point(0, 134217727);
		expect(l.intersects(c)).toBeTrue();
		expect(l.toString()).toEqual("y = 7.450580596923828e-9x + 134217727");
	});
	it('should be vertical', () => {
		const a = new Point(5, 7);
		const b = new Point(5, 3);
		const l = new Line(a, b);
		const c = new Point(5, 9);
		expect(l.intersects(c)).toBeTrue();
		expect(l.toString()).toEqual("x = 5");
	});
	it('should be horizontal', () => {
		const a = new Point(7, 5);
		const b = new Point(3, 5);
		const l = new Line(a, b);
		const c = new Point(9, 5);
		expect(l.intersects(c)).toBeTrue();
		expect(l.toString()).toEqual("y = 0x + 5");
	});
	it('should slope upward', () => {
		const a = new Point(1, 2);
		const b = new Point(5, 4);
		const l = new Line(a, b);
		const c = new Point(7, 5);
		expect(l.intersects(c)).toBeTrue();
		expect(l.toString()).toEqual("y = 0.5x + 1.5");
	});
	it('should slope downward', () => {
		const a = new Point(1, 4);
		const b = new Point(5, 2);
		const l = new Line(a, b);
		const c = new Point(3, 3);
		expect(l.intersects(c)).toBeTrue();
		expect(l.toString()).toEqual("y = -0.5x + 4.5");
	});
	it('should be vertical when underspecified', () => {
		const a = new Point(2, -5);
		const b = new Point(2, -5);
		const l = new Line(a, b);
		const c = new Point(-5, 2);
		expect(l.intersects(c)).toBeFalse();
		const d = new Point(2, 7);
		expect(l.intersects(d)).toBeTrue();
		expect(l.toString()).toEqual("x = 2");
	});
});
