#pragma once

typedef struct {
	unsigned steps;
	unsigned intersections;
} WalkResults;

WalkResults walk(unsigned n, unsigned k, unsigned* seed);
