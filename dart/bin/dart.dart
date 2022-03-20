import 'package:dart/main.dart';

void main(List<String> arguments) {
	final n = 4;
	final k = 1000;
	final runs = 1000000;
	final results = computeAverages(n, k, runs);
	print('Average of $runs runs is ${results[0]} steps and '
			'${results[1]} intersections');
}
