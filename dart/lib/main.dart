import 'walker.dart';
import 'dart:io';
import 'dart:isolate';
import 'dart:math';
import 'package:collection/collection.dart';

Future<List<int>> worker(int n, int k, int runs) async {
	int steps = 0;
	int intersections = 0;
	final rng = Random();
	for (int i = 0; i < runs; i += 1) {
		final w = Walker(rng, n, k);
		steps += w.steps();
		intersections += w.intersections();
	}
	return [steps, intersections];
}

Future<List<double>> computeAverages(int n, int k, int runs) async {
	final cores = Platform.numberOfProcessors;
	final futures = <Future<List<int>>>[];
	final each = runs ~/ cores;
	final extra = runs % cores;
	futures.add(Isolate.run(() => worker(n, k, each + extra)));
	for (int i = 0; i < cores - 1; i += 1) {
		futures.add(Isolate.run(() => worker(n, k, each)));
	}
	int steps = 0;
	int intersections = 0;
	final results = await Future.wait(futures);
	for (final result in results) {
		steps += result[0];
		intersections += result[1];
	}
	return [steps / runs, intersections / runs];
}
