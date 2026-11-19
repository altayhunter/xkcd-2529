import line;

struct BestLine {
	points: i64,
	best_fit: Line,
}

fn create_best_line(points: Point[:]) -> BestLine {
	if points.len < 2 {
		let zero = Point { 0, 0 };
		let line = create_line(zero, zero);
		return BestLine { points.len, line };
	}
	var max_i = 0;
	var max_l = create_line(points[0], points[1]);
	for i in points.len {
		for j in i+1..points.len {
			let a = points[i];
			let b = points[j];
			let l = create_line(a, b);
			let intersections = 2 + points[j+1..].filter() { l.intersects(it) }.len;
			if intersections > max_i {
				max_i = intersections;
				max_l = l;
			}
		}
	}
	BestLine { max_i, max_l }
}

fn format(out: u8[>..]&, bl: BestLine) {
	format(out, bl.best_fit);
}
