#include <stdio.h>
#include "binary-tree.h"

int main()
{
	struct Tree * tree = create_tree(1, "value1");
	insert_to_tree(tree, 2, "value2");
	insert_to_tree(tree, 1, "new value");
	printf("%s", find_value(tree, 1));
	return 0;
}
