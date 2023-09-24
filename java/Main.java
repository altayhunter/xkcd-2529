import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

public class Main {
	public static Pair<Integer> worker(int n, int k, int runs) {
		int steps = 0;
		int intersections = 0;
		for (int i = 0; i < runs; i++) {
			Walker w = new Walker(n, k);
			steps += w.steps();
			intersections += w.intersections();
		}
		return new Pair<>(steps, intersections);
	}

	public static Pair<Double> compute_averages(int n, int k, int runs)
			throws InterruptedException, ExecutionException {
		int cores = Runtime.getRuntime().availableProcessors();
		List<CompletableFuture<Pair<Integer>>>
				futures = new ArrayList<>();
		int each = runs / cores;
		int extra = runs % cores;
		futures.add(CompletableFuture.supplyAsync(() ->
			worker(n, k, each + extra)
		));
		for (int i = 0; i < cores - 1; i++) {
			futures.add(CompletableFuture.supplyAsync(() ->
				worker(n, k, each)
			));
		}
		int steps = 0;
		int intersections = 0;
		for (CompletableFuture<Pair<Integer>> f : futures) {
			Pair<Integer> p = f.get();
			steps += p.first;
			intersections += p.second;
		}
		return new Pair<>(
			steps / (double)runs,
			intersections / (double)runs
		);
	}

	public static void main(String[] args)
			throws InterruptedException, ExecutionException {
		int n = 4;
		int k = 1000;
		int runs = 1000000;
		Pair<Double> result = compute_averages(n, k, runs);
		System.out.println("Average of " + runs + " runs is " +
				result.first + " steps and " + result.second +
				" intersections");
	}
}
