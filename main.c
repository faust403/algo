#include <stdio.h>
#include "linked-list.h"

int main()
{
	struct List * list = create_list();
	add_to_list(list, "value1");
	add_to_list(list, "value2");

	print_list(list);

	clear_list(list);

	print_list(list); //ничего не должно выводиться
	
	return 0;
}
