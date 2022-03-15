#include <stdio.h>

#include "binary-tree.h"

int main()
{
	struct BTree * btree = create_BTree();
	add_to_BTree(btree, 1, "value1");
	add_to_BTree(btree, 0, "value2");

	remove_from_BTree(btree, 1);

	return 0;
}
