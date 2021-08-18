#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "linked-list.h"
#include "list.h"

void list_add_int(struct List* list, int value)
{
	list_add(list, &value);
}

void list_add_double(struct List* list, double value)
{
	list_add(list, &value);
}

void list_add_string(struct List* list, const char* value)
{
	list_add(list, value);
}

void print_int(const void* value)
{
	printf("%d\n", *(const int*)value);
}

void print_double(const void* value)
{
	printf("%lf\n", *(const double*)value);
}

int main()
{
	struct List* l3 = list_create_string();
	list_add_string(l3, "foo");
	list_add_string(l3, "bar");
	list_add_string(l3, "baz");
	list_add_string(l3, "qux");
	list_add_string(l3, "quxx");
	list_for_each(l3, puts);

	struct ListNode* old_node;
	if (list_try_find(l3, "baz", &old_node)) {
		size_t buffer_size = strlen("zab") + 1;
		struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode) + buffer_size);

		if (new_node != 0) {
			new_node->next = 0;
			strcpy_s(&new_node->value[0], buffer_size, "zab");

			list_change_node(l3, old_node, new_node);
			free(old_node);
		}
	}

	list_for_each(l3, puts);
	list_free(l3);
	//struct List* l1 = list_create_int();
	//struct List* l2 = list_create_double();

	//list_add_int(l1, 1);
	//list_add_int(l1, 2);
	//list_add_int(l1, 3);
	//list_for_each(l1, print_int);

	//list_add_double(l2, 2.718281);
	//list_add_double(l2, 3.141592);
	//list_add_double(l2, 1.414213);
	//list_for_each(l2, print_double);
	//list_free(l1);
	//list_free(l2);

	//struct List * list = create_list();
	//add_to_list(list, "value1");
	//add_to_list(list, "value2");

	//printf("print after add\n");
	//print_list(list);

	//remove_at(list, 0);

	//printf("print after remove node\n");
	//print_list(list);

	//clear_list(list);

	//printf("print after cleaning\n");
	//print_list(list);

	//free_list(list);

	//printf("print after free\n");
	//list = create_list();
	//print_list(list);
	//return 0;
}
