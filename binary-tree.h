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

struct Tree * create_tree(unsigned int key, char * value)
{                                                               
	struct Tree * tree = (struct Tree *)malloc(sizeof(struct Tree));
        tree->head = create_node(NULL, key, value);
	tree->head->childRight = NULL;
	tree->head->childLeft = NULL;

	return tree;
}

void insert_to_tree(struct Tree * tree, unsigned int key, char * value)
{
	if(tree == NULL || tree->head == NULL)
		return;

	struct Node * currentNode = tree->head;

	while(currentNode != NULL)
	{
		if(currentNode->key < key)
		{
			if(currentNode->childRight != NULL)
			{
				if(currentNode->childRight->key > key){
					struct Node * newNode = create_node(currentNode, key, value);
					newNode->childRight = currentNode->childRight;
					currentNode->childRight = newNode;
					return;
				}
				currentNode = currentNode->childRight;
				continue;
			}
			currentNode->childRight = create_node(currentNode, key, value);
			return;
		} else if(currentNode->key > key)
		{
			if(currentNode->childLeft != NULL)
			{
				if(currentNode->childLeft->key < key)
				{
					struct Node * newNode = create_node(currentNode, key, value);
					newNode->childLeft = currentNode->childLeft;
					currentNode->childLeft = newNode;
					return;
				}
				currentNode = currentNode->childLeft;
				continue;
			}
			currentNode->childLeft = create_node(currentNode, key, value);
			return;
		} else if(currentNode->key == key)
		{
			currentNode->value = value;
			return;
		}
	}
}

struct Node * find_node(struct Tree * tree, unsigned int key)
{
	if(tree == NULL)
		return NULL;
	struct Node * currentNode = tree->head;
	while(currentNode != NULL)
	{
		if(currentNode->key < key)
		{
			currentNode = currentNode->childRight;
		} else if(currentNode->key > key)
		{
			currentNode = currentNode->childLeft;
		} else if(currentNode->key == key)
			return currentNode;
	}
	return NULL;
}

char * find_value(struct Tree * tree, unsigned int key)
{
	if(find_node(tree, key) == NULL)
		return NULL;
	return find_node(tree, key)->value;
}

void remove_from_tree(struct Tree * tree, char * key);

#endif
