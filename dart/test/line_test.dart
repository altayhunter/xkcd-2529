import 'package:dart/line.dart';
import 'package:dart/point.dart';
import 'package:test/test.dart';

void main() {
	test('line no rounding error symmetric', () {
		final a = Point(1001, 1);
		final b = Point(-1000, -1);
		final l = Line(a, b);
		final c = Point(0, 0);
		expect(l.intersects(c), false);
		final d = Point(3002, 3);
		expect(l.intersects(d), true);
	});

	test('line no rounding error asymmetric', () {
		final a = Point(100000, 100000);
		final b = Point(-1, 0);
		final l = Line(a, b);
		final c = Point(0, 1);
		expect(l.intersects(c), false);
		final d = Point(200001, 200000);
		expect(l.intersects(d), true);
	});

	test('line largest no rounding error', () {
		final a = Point(134217726, 134217727);
		final b = Point(-1, 134217726);
		final l = Line(a, b);
		final c = Point(0, 134217726);
		expect(l.intersects(c), false);
		expect(l.toString(), 'y = 7.45058065243498e-9x + 134217726.00000001');
	});

	test('line smallest rounding error', () {
		final a = Point(134217727, 134217728);
		final b = Point(-1, 134217727);
		final l = Line(a, b);
		final c = Point(0, 134217727);
		expect(l.intersects(c), true);
		expect(l.toString(), 'y = 7.450580596923828e-9x + 134217727.0');
	});

	test('line vertical', () {
		final a = Point(5, 7);
		final b = Point(5, 3);
		final l = Line(a, b);
		final c = Point(5, 9);
		expect(l.intersects(c), true);
		expect(l.toString(), 'x = 5.0');
	});

	test('line horizontal', () {
		final a = Point(7, 5);
		final b = Point(3, 5);
		final l = Line(a, b);
		final c = Point(9, 5);
		expect(l.intersects(c), true);
		expect(l.toString(), 'y = 0.0x + 5.0');
	});

	test('line upward', () {
		final a = Point(1, 2);
		final b = Point(5, 4);
		final l = Line(a, b);
		final c = Point(7, 5);
		expect(l.intersects(c), true);
		expect(l.toString(), 'y = 0.5x + 1.5');
	});

	test('line downward', () {
		final a = Point(1, 4);
		final b = Point(5, 2);
		final l = Line(a, b);
		final c = Point(3, 3);
		expect(l.intersects(c), true);
		expect(l.toString(), 'y = -0.5x + 4.5');
	});

	test('line same points', () {
		final a = Point(2, -5);
		final b = Point(2, -5);
		final l = Line(a, b);
		final c = Point(-5, 2);
		expect(l.intersects(c), false);
		final d = Point(2, 7);
		expect(l.intersects(d), true);
		expect(l.toString(), 'x = 2.0');
	});
}
