/*
Program: Dynamic array ADT
Filename: DynArrDriver.c
Description: Driver file to test DynArr implmentation.
*/

#include "DynArr.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct DynArr testData;

	initDynArr(&testData, 10);

	for(int i = 0; i < 45; i++){
		addDynArr(&testData, i);
	}

	/*
	for(int j = 0; j < testData.size; j++){
		printf("%i\n", testData.data[j]);
	}

	printf("testData Capacity is... %i.\n", testData.capacity);
	*/

	freeDynArr(&testData);

}
