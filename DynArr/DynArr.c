/*
Program: Dynamic array ADT
Filename: DynArr.c
Description: Implementation file for the dynamic array
Notes: Using "Worksheet 14 Dyn Arr" as reference.
*/

// TODO: have "possible" mem leaks per valgrind. need to investigate

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "DynArr.h"


void initDynArr(struct DynArr *v, int capacity){
	
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);

	v->size = 0;
	v->capacity = capacity;

}

void freeDynArr(struct DynArr *v){

	if(v->data != 0){
		free(v->data);	/*free the space on the heap*/
		v->data = NULL;
	}
	v->size = 0;
	v->capacity = 0;
}

int sizeDynArr(struct DynArr *v){

	return v->size;
}

void addDynArr(struct DynArr *v, TYPE val){
	
	/*Check to see if a resize is necessary*/
	if(v->size >= v->capacity){
		_setCapacityDynArr(v, 2 * v->capacity);
	}
	v->data[v->size] = val;
	v->size++;
}

void _setCapacityDynArr(struct DynArr *v, int newCap){

	v->data = (TYPE *)realloc(v->data, newCap * sizeof(TYPE));
	assert(v->data != 0);
	v->capacity = newCap;

	/* 2nd implementation using malloc...
	
	TYPE *tempData = malloc(sizeof(TYPE) * newCap);

	for(int i = 0; i < v->size; i++){
		tempData[i] = v->data[i];
	}

	free(v->data);

	v->data = tempData;
	v->capacity = newCap;
	*/


	/* 3rd implementation using DynArr functions...

	// Create new DynArr struct to hold larger array
	struct DynArr myNewData;

	// Initialize new DynArr struct w/ larger capacity
	initDynArr(&myNewData, newCap);	
	
	//Copy values of old array into newly created array
	for(int i = 0; i < v->size; i++){
		addDynArr(&myNewData, v->data[i]);
	}

	// Free memory used by old array
	freeDynArr(v);

	// Point v to new DynArr struct
	*v = myNewData;
	*/
}
