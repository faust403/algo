#include "./bubble-sort.h"

int maxEl(int* array, int size)
{
	int res = array[0];
	size = size-1;

	for(int i = 0; i < size; i += 1)
	{
		if(res < array[i])
			res = array[i];
	}
	return res;
}

int minEl(int* array, int size)
{
	int res = array[0];
	size = size-1;

	for(int i = 0; i < size; i += 1)
	{
		if(res > array[i])
			res = array[i];
	}
	return res;
}

void swap(void * _a, void * _b)
{
	int temp = *(int*)_a;
	*(int*)_a = *(int*)_b;
	*(int*)_b = temp;
}

void bubble_sort(int* array, int size)
{
	while(array[0] != minEl(array, size) && array[size-1] != maxEl(array, size))
	{
		for(int i = 0; i < size; i += 1)
		{
			if(array[i] > array[i+1])
				swap(&array[i], &array[i+1]);
		}
	}
}
