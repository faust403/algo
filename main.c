#include <stdio.h>
#include "binary-tree.h"

int main()
{
	struct Tree * tree = create_tree();
	insert_to_tree(tree, 10, "value");
	insert_to_tree(tree, 12, "value2");
	remove_from_tree(tree, 12);
	printf("%s", find_value(tree, 12));
	return 0;
}
