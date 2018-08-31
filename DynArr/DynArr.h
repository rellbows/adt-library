/*
Program: Dynamic array ADT
Filename: DynArr.h
Description: Header file for the dynamic array
Notes: Using "Worksheet 14 Dyn Arr" as reference.
*/

# ifndef TYPE
# define TYPE int
# endif

# ifndef DYNARR_H
# define DYNARR_H

struct DynArr
{
	TYPE *data;	// pointer to data array
	int size;	// number of elements in array
	int capacity;	// how big array is
};

void initDynArr(struct DynArr *v, int capacity);

void freeDynArr(struct DynArr *v);

int sizeDynArr(struct DynArr *v);

void addDynArr(struct DynArr *v, TYPE val);

void _setCapacityDynArr(struct DynArr *v, int newCap);

#endif
