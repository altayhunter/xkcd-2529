class Line {
	constructor(a, b) {
		this.slope = (a.y - b.y) / (a.x - b.x);
		this.intercept = a.x === b.x ? a.x : a.y - this.slope * a.x;
	}
	intersects(p) {
		if (!isFinite(this.slope)) {
			return p.x === this.intercept;
		}
		return p.y === this.slope * p.x + this.intercept;
	}
	toString() {
		if (!isFinite(this.slope)) {
			return `x = ${this.intercept}`;
		}
		return `y = ${this.slope}x + ${this.intercept}`;
	}
}

export {
	Line,
};
