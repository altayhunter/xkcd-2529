import { BestLine } from './bestline.mjs';
import { Point } from './point.mjs';

class Walker {
	constructor(n, k) {
		let location = new Point(0, 0);
		this.marbles = [];
		this.visited = new Set([location.toString()]);
		if (n == 0 || k == 0) return;
		while (!this.trapped(location)) {
			const desired = this.valid_neighbor(location);
			if (this.visited.size % n == 0) {
				this.marbles.push(desired);
			}
			this.visited.add(desired.toString());
			location = desired;
			if (this.visited.size > n * k) {
				break;
			}
		}
	}
	steps() {
		return this.visited.size;
	}
	intersections() {
		return new BestLine(this.marbles).intersections();
	}
	trapped(p) {
		return this.visited.has(p.up().toString()) &&
				this.visited.has(p.right().toString()) &&
				this.visited.has(p.down().toString()) &&
				this.visited.has(p.left().toString());
	}
	valid_neighbor(p) {
		let neighbor = this.random_neighbor(p);
		while (this.visited.has(neighbor.toString())) {
			neighbor = this.random_neighbor(p);
		}
		return neighbor;
	}
	random_neighbor(p) {
		switch (Math.floor(Math.random() * 4)) {
			case 0: return p.up();
			case 1: return p.right();
			case 2: return p.down();
			default: return p.left();
		}
	}
}

export {
	Walker,
};
