import 'package:dart/point.dart';
import 'package:test/test.dart';

void main() {
	test('point construction', () {
		final origin = Point(0, 0);
		expect(origin.toString(), '(0, 0)');
		final negatives = Point(-5, -7);
		expect(negatives.toString(), '(-5, -7)');
	});

	test('point neighbors', () {
		final point = Point(-4, 7);
		expect(point, isNot(equals(point.right())));
		expect(point, point.left().right());
		expect(point, point.up().down());
		expect(point.up().right(), point.right().up());
	});
}
