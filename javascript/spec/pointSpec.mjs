import { Point } from '../point.mjs';

describe('Point', () => {
	it('should match self', () => {
		const p = new Point(7, -3);
		expect(p).toEqual(new Point(7, -3));
	});
	it('should not match neighbors', () => {
		const p = new Point(0, 0);
		expect(p).not.toEqual(p.up());
		expect(p).not.toEqual(p.right());
		expect(p).not.toEqual(p.down());
		expect(p).not.toEqual(p.left());
	});
	it('should loop back to itself', () => {
		const p = new Point(-2, 9);
		expect(p.up().right().down().left()).toEqual(p);
	});
	it('should convert to string', () => {
		const p = new Point(0, -4);
		expect(p.toString()).toEqual('{"x":0,"y":-4}');
	});
});
