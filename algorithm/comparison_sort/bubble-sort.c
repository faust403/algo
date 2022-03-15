#include "./bubble-sort.h"

static int maxEl(int* array, int size)
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

static int minEl(int* array, int size)
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

static void swap(void * _a, void * _b)
{
	int temp = *(int*)_a;
	*(int*)_a = *(int*)_b;
	*(int*)_b = temp;
}

void bubble_sort(int* array, int size)
{
	for(int i = 0; i < size; i += 1)
	{
		for(int j = 0; j < size; j += 1)
		{
			if(array[j] > array[j+1])
				swap(&array[j], &array[j+1]);
		}
	}
}
