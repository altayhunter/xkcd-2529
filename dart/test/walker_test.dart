import 'package:dart/walker.dart';
import 'package:dart/point.dart';
import 'package:test/test.dart';
import 'dart:math';

void main() {
	test('no marbles', () {
		final rng = Random();
		final w = Walker(rng, 0, 5);
		expect(w.steps(), 1);
		expect(w.intersections(), 0);
	});

	test('no steps', () {
		final rng = Random();
		final w = Walker(rng, 4, 0);
		expect(w.steps(), 1);
		expect(w.intersections(), 0);
	});

	test('double zero', () {
		final rng = Random();
		final w = Walker(rng, 0, 0);
		expect(w.steps(), 1);
		expect(w.intersections(), 0);
	});

	test('marble placement', () {
		final rng = Random();
		final w = Walker(rng, 4, 1);
		expect(w.marbles.length, 1);
		final hasEvenParity = (Point p) => (p.x + p.y) % 2 == 0;
		expect(hasEvenParity(w.marbles[0]), isTrue);
	});

	test('normal inputs', () {
		final rng = Random();
		final w = Walker(rng, 3, 5);
		expect(w.steps(), greaterThanOrEqualTo(8));
		expect(w.steps(), lessThanOrEqualTo(16));
		expect(w.intersections(), greaterThanOrEqualTo(2));
		expect(w.intersections(), lessThanOrEqualTo(5));
	});
}
