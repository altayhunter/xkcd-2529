import 'package:dart/main.dart';
import 'package:test/test.dart';

void main() {
	test('n=1, k=1000', () {
		final n = 1;
		final k = 1000;
		final runs = 100;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 71.95).abs(), lessThan(21.0));
		expect((results[1] - 11.0).abs(), lessThan(1.6));
	});

	test('n=2, k=1000', () {
		final n = 2;
		final k = 1000;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 71.95).abs(), lessThan(7.0));
		expect((results[1] - 7.44).abs(), lessThan(0.35));
	});

	test('n=3, k=1000', () {
		final n = 3;
		final k = 1000;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 71.95).abs(), lessThan(7.0));
		expect((results[1] - 4.57).abs(), lessThan(0.3));
	});

	test('n=4, k=1000', () {
		final n = 4;
		final k = 1000;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 71.95).abs(), lessThan(7.0));
		expect((results[1] - 4.37).abs(), lessThan(0.2));
	});

	test('n=5, k=1000', () {
		final n = 5;
		final k = 1000;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 71.95).abs(), lessThan(7.0));
		expect((results[1] - 3.33).abs(), lessThan(0.2));
	});

	test('n=10, k=1', () {
		final n = 10;
		final k = 1;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 10.98).abs(), lessThan(0.2));
		expect((results[1] - 0.99).abs(), lessThan(0.01));
	});

	test('n=1, k=10', () {
		final n = 1;
		final k = 10;
		final runs = 1000;
		final results = computeAverages(n, k, runs);
		expect((results[0] - 10.98).abs(), lessThan(0.1));
		expect((results[1] - 4.56).abs(), lessThan(0.1));
	});
}
