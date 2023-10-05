# xkcd 2529
This repository contains implementations of the "weirdly concrete" math problem presented in [xkcd.com/2529](https://xkcd.com/2529/). Note that contrary to a strict reading of the text I have interpreted "the longest line" to mean "the line with the most marbles" because that is what the example given in the comic illustrates.

## Trapping
The problem describes a random walker on a two-dimensional grid that never revisits any square. Such a walker will inevitably trap itself eventually. On an infinite grid the random walker will step on 71.7 squares on average before it traps itself.

## Results
### Varying both parameters
For small values of `n` and `k`, either decreasing `n` or increasing `k` tends to increase the number of marbles on the longest line. Additionally, odd values of `n` tend to produce lower results than similar even values. It may be surprising that the result can be below 1, but this is because for sufficiently large values of `n` the walker traps itself before it gets the chance to drop its first marble.

| n \ k | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|------|------|------|------|------|------|------|------|------|------|
| 1 | 1.00 | 2.00 | 2.33 | 2.70 | 3.24 | 3.45 | 3.75 | 4.04 | 4.34 | 4.56 |
| 2 | 1.00 | 2.00 | 2.20 | 2.60 | 3.03 | 3.27 | 3.50 | 3.75 | 3.99 | 4.20 |
| 3 | 1.00 | 2.00 | 2.12 | 2.29 | 2.54 | 2.75 | 2.94 | 3.08 | 3.19 | 3.29 |
| 4 | 1.00 | 2.00 | 2.10 | 2.32 | 2.58 | 2.82 | 3.00 | 3.14 | 3.25 | 3.37 |
| 5 | 1.00 | 1.99 | 2.05 | 2.15 | 2.29 | 2.44 | 2.59 | 2.71 | 2.80 | 2.87 |
| 6 | 1.00 | 1.98 | 2.05 | 2.18 | 2.37 | 2.54 | 2.69 | 2.79 | 2.87 | 2.93 |
| 7 | 1.00 | 1.97 | 2.00 | 2.06 | 2.16 | 2.25 | 2.35 | 2.44 | 2.50 | 2.55 |
| 8 | 0.997 | 1.95 | 1.99 | 2.09 | 2.22 | 2.34 | 2.45 | 2.53 | 2.59 | 2.63 |
| 9 | 0.995 | 1.93 | 1.95 | 1.99 | 2.06 | 2.12 | 2.19 | 2.25 | 2.29 | 2.33 |
| 10 | 0.990 | 1.90 | 1.94 | 2.01 | 2.10 | 2.19 | 2.26 | 2.32 | 2.36 | 2.39 |

### Large values of k
Any sufficiently large value of `k` is equivalent to any other, because the walker will have trapped itself before `n*k` is reached anyway. When the multiple is larger than about 200 it begins to be irrelevant. As a result, it's interesting to see how varying `n` alone affects the result for any large value of `k`.

| n | intersections |
|---|------|
| 1 | 11.0 |
| 2 | 7.44 |
| 3 | 4.57 |
| 4 | 4.37 |
| 5 | 3.33 |
| 6 | 3.34 |
| 7 | 2.75 |
| 8 | 2.81 |
| 9 | 2.42 |
| 10 | 2.47 |
| 11 | 2.20 |
| 12 | 2.24 |
| 13 | 2.04 |
| 14 | 2.06 |
| 15 | 1.90 |
| 16 | 1.92 |
| 17 | 1.79 |
| 18 | 1.80 |
| 19 | 1.70 |
| 20 | 1.70 |
| 21 | 1.62 |
| 22 | 1.60 |
| 23 | 1.54 |
| 24 | 1.52 |
| 25 | 1.46 |
| 26 | 1.45 |
| 27 | 1.40 |
| 28 | 1.38 |
| 29 | 1.33 |
| 30 | 1.31 |
| 31 | 1.27 |
| 32 | 1.25 |
| 33 | 1.21 |
| 34 | 1.19 |
| 35 | 1.15 |
| 36 | 1.13 |
| 37 | 1.10 |
| 38 | 1.08 |
| 39 | 1.05 |
| 40 | 1.03 |
| 41 | 0.999 |
| 42 | 0.978 |
| 43 | 0.952 |
| 44 | 0.931 |
| 45 | 0.908 |
| 46 | 0.887 |
| 47 | 0.865 |
| 48 | 0.845 |
| 49 | 0.823 |
| 50 | 0.805 |

## Performance
Each of the implementations averaged the results of a million runs with `n=4` and `k=1000`. They were run on an Intel Core i5-4200U.
* Rust: 5.5 seconds
* Kotlin: 11 seconds
* C: 13 seconds
* C++: 14 seconds
* Go: 15 seconds
* Java: 24 seconds
* Dart: 97 seconds
* JavaScript: 115 seconds
* Python: 239 seconds
