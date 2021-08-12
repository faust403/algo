#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "hash-table.h"

int main()
{
	struct Node * hash_table[1024] = create_hash_table();
	add_to_table(hash_table, create_list());
	add_to_table(hash_table, create_node("key1", "value1"));
	add_to_table(hash_table, create_node("key2", "value2"));

	return 0;
}
