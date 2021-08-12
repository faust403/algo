#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	char * key;
	char * value;

	struct Node * parent;
	struct Node * childLeft;
	struct Node * childRight;
};

struct Tree
{
	struct Node * head;
};

struct Tree * create_tree()
{
	struct Tree * tree = (struct Tree *)malloc(sizeof(struct Tree));

	tree->head = NULL;
	return tree;
}

struct Node * create_node(char * key, char * value)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));

	node->key = key;
	node->value = value;
	node->childLeft = NULL;
	node->childRight = NULL;
}

void insert_to_tree(struct Tree * tree, char * key, char * value)
{
	if(tree == NULL)
	{
		tree->head = create_node(key, value);
		return;
	} else if(key > tree->head->key) {

		tree->head = create_node(key, value);
		return;
	} else if(key < tree->head->key) {

		tree->head = create_node(key, value);
		return;
	} else if(key == tree->head->key) {

		tree->head->value = value;
		return;
	}
}
#endif
