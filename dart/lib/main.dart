import 'walker.dart';
import 'dart:math';
import 'package:collection/collection.dart';

List<double> computeAverages(int n, int k, int runs) {
	final steps = <int>[];
	final intersections = <int>[];
	final rng = Random();
	for (int i = 0; i < runs; i += 1) {
		final w = Walker(rng, n, k);
		steps.add(w.steps());
		intersections.add(w.intersections());
	}
	return [steps.average, intersections.average];
}
