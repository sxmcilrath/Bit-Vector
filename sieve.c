#include <stdio.h>

#include "bitvector.h"

int
main(void)
{
	int n, i, j;
	struct bit_vector *vec;

	printf("Enter max int-> ");
	scanf("%d", &n);

	vec = bv_create(n + 1);

	// add code here


	return 0;
}
