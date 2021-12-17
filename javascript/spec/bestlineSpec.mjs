import { Point } from '../point.mjs';
import { BestLine } from '../bestline.mjs';

describe('Line', () => {
	it('should handle four horizontal three vertical', () => {
		const list = [
			new Point(0, 1),
			new Point(1, 1),
			new Point(1, 0),
			new Point(2, 1),
			new Point(1, 2),
			new Point(3, 1),
		];
		const bl = new BestLine(list);
		expect(bl.toString()).toEqual("y = 0x + 1");
		expect(bl.points).toEqual(4);
	});
	it('should handle three diagonal two horizontal', () => {
		const list = [
			new Point(3, 3),
			new Point(5, 3),
			new Point(2, 0),
			new Point(4, 6),
		];
		const bl = new BestLine(list);
		expect(bl.toString()).toEqual("y = 3x + -6");
		expect(bl.points).toEqual(3);
	});
});
