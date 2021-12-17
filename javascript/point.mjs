class Point {
	constructor(x, y) {
		this.x = x;
		this.y = y;
	}
	up() {
		return new Point(this.x, this.y+1);
	}
	right() {
		return new Point(this.x+1, this.y);
	}
	down() {
		return new Point(this.x, this.y-1);
	}
	left() {
		return new Point(this.x-1, this.y);
	}
	toString() {
		return JSON.stringify({
			x: this.x,
			y: this.y,
		});
	}
}

export {
	Point,
};
