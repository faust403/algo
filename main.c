#include <stdio.h>
#include "binary-tree.h"

int main()
{
	struct Tree * tree = create_tree(1, "value");
	insert_to_tree(tree, 1, "value");
	printf("%s", find_value(tree, 1));
	return 0;
}
