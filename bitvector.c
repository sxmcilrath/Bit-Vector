#include <stdlib.h>

#include "bitvector.h"

int numBytes(int bits){
	return (bits+7)/8;
}

struct bit_vector *
bv_create(int size)
{
	//allocate space for vector
	struct bit_vector *p = malloc(sizeof(struct bit_vector));

	//assign vals for field and allocate space for vector
	p->size = size;
	p->vector = calloc(numBytes(size),sizeof(unsigned char));
	return p;
}

void
bv_destroy(struct bit_vector *v)
{
	//clear bit vector vals first
	v->vector = NULL;	
	v->size = 0;
	free(v);
}

int bv_contains(struct bit_vector *v, int i)
{
	int byte = i/8;	//generates the byte we want to look at
	int bit = i%8;	//generates the exact bit that we want to check = to 1

	if(v->vector[byte]>>(7-bit) & 1){	//compares the target bit to 1 to see if set
		return 1;
	}
	else{return 0;} 
	
	return -1;
}

void
bv_insert(struct bit_vector *v, int i)
{
	int byte = i/8;
	int bit = i%8;

	v->vector[byte] |= 1<<(7-bit);

}

void
bv_remove(struct bit_vector *v, int i)
{
	int byte = i/8;
	int bit = i%8;
	v->vector[byte] &= (~(1<<(7-bit)));
	
}

struct bit_vector *
bv_complement(struct bit_vector *v)
{
	struct bit_vector *v2 = bv_create(v->size);	//create bit vector to return
	int bytes = numBytes(v->size);		//generate num of bytes
	int i;
	for(i = 0; i < bytes; i++){
		v2->vector[i] = ~(v->vector[i]);
	}
	return v2;
}

struct bit_vector *
bv_union(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *v3 = bv_create(v1->size);	//create bit vector to return
	int bytes = numBytes(v1->size);		//create num of bytes
	int i;
	for(i = 0; i < bytes; i++){
		v3->vector[i] = (v1->vector[i]) | (v2->vector[i]);	//takes nums that are in either vector
	}
	return v3;
}

struct bit_vector *
bv_intersection(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *v3 = bv_create(v1->size);	//create bit vector to return
	int bytes = numBytes(v1->size);		//create num of bytes
	int i;
	for(i = 0; i < bytes; i++){
		v3->vector[i] = (v1->vector[i]) & (v2->vector[i]);	//takes nums that both vectors contain
	}
	return v3;
}

struct bit_vector *
bv_difference(struct bit_vector *v1, struct bit_vector *v2)
{
	struct bit_vector *v3 = bv_create(v1->size);	//create bit vector to return
	int bytes = numBytes(v1->size);		//create num of bytes
	int i;
	for(i = 0; i < bytes; i++){
		v3->vector[i] = (v1->vector[i]) & (~(v2->vector[i]));	//take the and of v1 and whatever is not in v2
	}
	return v3;
}
