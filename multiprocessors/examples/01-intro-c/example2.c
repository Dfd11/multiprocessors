// =================================================================
//
// File: example2.c
// Author: Pedro Perez
// Description: This file contains the code that searches for the
// 				smallest value stored in an array. The time this
//				implementation takes will be used as the basis to
//				calculate the improvement obtained with parallel
//				technologies.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

#define SIZE 1000000000 //1e9

int min_value(int *array, int size) {
	int i, result;

	result = INT_MAX;
	for (i = 0; i < size; i++) {
		result = MMIN(result, array[i]);
	}
	return result;
}

int main(int argc, char* argv[]) {
	int i, *a, pos, result;
	double ms;

	a = (int *) malloc(sizeof(int) * SIZE);
	random_array(a, SIZE);
	display_array("a", a);

	srand(time(0));
	pos = rand() % SIZE;
	printf("Setting value 0 at %i\n", pos);
	a[pos] = 0;

	printf("Starting...\n");
	ms = 0;
	for (i = 0; i < N; i++) {
		start_timer();

		result = min_value(a, SIZE);

		ms += stop_timer();
	}
	printf("result = %i\n", result);
	printf("avg time = %.5lf ms\n", (ms / N));

	free(a);
	return 0;
}
