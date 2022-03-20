import 'package:dart/bestline.dart';
import 'package:dart/point.dart';
import 'package:test/test.dart';

void main() {
	test('four horizontal three vertical', () {
		final list = <Point>[
			Point(0, 1),
			Point(1, 1),
			Point(1, 0),
			Point(2, 1),
			Point(1, 2),
			Point(3, 1),
		];
		final bl = BestLine(list);
		expect(bl.toString(), 'y = -0.0x + 1.0');
		expect(bl.points, 4);
	});

	test('four horizontal three vertical', () {
		final list = <Point>[
			Point(3, 3),
			Point(5, 3),
			Point(2, 0),
			Point(4, 6),
		];
		final bl = BestLine(list);
		expect(bl.toString(), 'y = 3.0x + -6.0');
		expect(bl.points, 3);
	});
}
