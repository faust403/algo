#include <stdio.h>
#include "linked-list.h"

int main()
{
	struct List * list = create_list();
	add_to_list(list, "value1");
	add_to_list(list, "value2");

	printf("print after add\n");
	print_list(list);

	remove_at(list, 0);

	printf("print after remove node\n");
	print_list(list);

	clear_list(list);

	printf("print after cleaning\n");
	print_list(list);

	free_list(list);

	printf("print after free\n");
	list = create_list();
	print_list(list);
	return 0;
}
