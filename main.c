#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "./struct/singleLink-list/list.h"
//#include "./struct/hash-table/hash.h"
#include "./algorithm/bubble-sort.h"

int main(int argc, char ** argv)
{
	int array[3] = {3, 2, 1};
	printf("sort beggining");
	
	bubble_sort(array, 3);
	printf("sort end");
	for(int i = 0; i < 3; i++)
	{
		printf("%d", array[i]);
	}
	return 0;
}
