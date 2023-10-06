import 'package:dart/main.dart';

void main(List<String> arguments) async {
	final n = 4;
	final k = 1000;
	final runs = 1000000;
	final results = await computeAverages(n, k, runs);
	print('Average of $runs runs is ${results[0]} steps and '
			'${results[1]} intersections');
}
