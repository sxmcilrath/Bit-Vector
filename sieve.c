#include <stdio.h>

#include "bitvector.h"

//copied from vectest
void
printVec(struct bit_vector *vec)
{
	int isFirst, i;
	printf("{");
	isFirst = 1;
	for (i = 0; i < vec->size; i++)
		if (bv_contains(vec, i)) {
			if (!isFirst)
				printf(", ");
			printf("%d", i);
			isFirst = 0;
		}
	printf("} \n"); 
}

int
main(void)
{
	int n, i, j;
	struct bit_vector *vec;

	printf("Enter max int-> ");
	scanf("%d", &n);

	vec = bv_create(n + 1);

	// add code here
	//first fill the vector with all nums from 2 to n
	for(i = 2; i < vec->size; i++){
		bv_insert(vec, i);
	}
	
	//loop through to remove
	for(i =2; i < vec->size; i++){
		
		//if i is still inside the list, a loop is started to remove 
		//all of its multiples
		if(bv_contains(vec,i)){
			
			//loops through incrementing by gaps of i
			for(j = i+i; j < vec->size; j+=i){
				bv_remove(vec,j);	//removes multiple
			}
		}
	
	}

	printVec(vec);	//print out vector
	bv_destroy(vec);
	return 0;
}
