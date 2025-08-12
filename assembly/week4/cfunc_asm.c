#include <stdio.h>

extern int test(int, int);

int test(int a, int b) {

	printf("This is the output of a test function.\n");
	return a + b;
}

