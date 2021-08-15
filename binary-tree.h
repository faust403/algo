#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	unsigned int key;
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

	tree->head->childRight = NULL;
	tree->head->childLeft = NULL;
	tree->head = NULL;
	return tree;
}

struct Node * create_node(struct Node * parent, unsigned int key, char * value)
{
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));

	node->key = key;
	node->value = value;
	node->childLeft = NULL;
	node->childRight = NULL;
	node->parent = parent;

	return node;
}

void insert_to_tree(struct Tree * tree, unsigned int key, char * value)
{
	if(tree == NULL)
		return;
	if(tree->head == NULL)
	{
		tree->head = create_node(NULL, key, value);
		return;
	}

	struct Node * currentNode = tree->head;

	while(currentNode != NULL)
	{
		if(currentNode->key < key)
		{
			if(currentNode->childRight != NULL)
			{
				currentNode = currentNode->childRight;
				continue;
			}
			currentNode->childRight = create_node(currentNode, key, value);
			return;
		} else if(currentNode->key > key)
		{
			if(currentNode->childLeft != NULL)
			{
				currentNode = currentNode->childLeft;
				continue;
			}
			currentNode->childLeft = create_node(currentNode, key, value);
			return;
		} else if(currentNode->key == key)
		{
			currentNode->value = value;	
		}
	}
}

void remove_from_tree(struct Tree * tree, char * key);

#endif
