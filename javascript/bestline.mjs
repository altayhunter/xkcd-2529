import { Line } from './line.mjs';
import { Point } from './point.mjs';

class BestLine {
	constructor(points) {
		if (points.length < 2) {
			const zero = new Point(0, 0);
			this.points = points.length;
			this.best_fit = new Line(zero, zero);
			return;
		}
		this.points = 0;
		this.best_fit = new Line(points[0], points[1]);
		for (let i = 0; i < points.length; i++) {
			for (let j = i + 1; j < points.length; j++) {
				const a = points[i];
				const b = points[j];
				const l = new Line(a, b);
				const intersections = 2 + points.slice(j + 1).filter(p => l.intersects(p)).length;
				if (intersections > this.points) {
					this.points = intersections;
					this.best_fit = l;
				}
			}
		}
	}
	intersections() {
		return this.points;
	}
	toString() {
		return this.best_fit.toString();
	}
}

export {
	BestLine,
};
