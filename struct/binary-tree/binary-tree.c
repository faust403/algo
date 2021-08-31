#include <malloc.h>

#include "binary-tree.h"

struct BTNode * create_BTNode(unsigned int key, char * value)
{
	struct BTNode * node = (struct BTNode*)malloc(sizeof(struct BTNode));
	if(node == NULL)
		return NULL;

	node->value = value;
	node->key = key;

	node->parent = NULL;
	node->childLeft = NULL;
	node->childRight = NULL;

	return node;
}

struct BTree * create_BTree()
{
	struct BTree * btree = (struct BTree*)malloc(sizeof(struct BTree));
	if(btree == NULL)
		return NULL;

	btree->root = NULL;

	return btree;
}

char * BTfind(struct BTree * btree, unsigned int key)
{
	if(btree == NULL || btree->root == NULL)
		return NULL;

	struct BTNode * currentNode = btree->root;
	while(currentNode != NULL)
	{
		if(currentNode->key > key)
                {
                        currentNode = currentNode->childRight;
                        continue;
                }
                if(currentNode->key < key)
                {                        
                        currentNode = currentNode->childLeft;
                        continue;
                }
		if(currentNode->key == key)
                {
                        return currentNode->value;
                }
	}
	return "";
}

void add_to_BTree(struct BTree * btree, unsigned int key, char * value)
{
	struct BTNode * BTnode = create_BTNode(key, value);
	
	if(btree == NULL)
	{
		btree = create_BTree();
		btree->root = BTnode;
		
		return;
	}
	if(btree->root == NULL)
	{
		btree->root = BTnode;

		return;
	}
	
	struct BTNode * currentNode = btree->root;
	while(currentNode != NULL)
	{
		if(currentNode->key > key)
		{
			if(currentNode->childRight == NULL)
			{
				currentNode->childRight = BTnode;
				BTnode->parent = currentNode;

				return;
			}
			currentNode = currentNode->childRight;
		}
		if(currentNode->key < key)
		{
			if(currentNode->childLeft == NULL)
			{
				currentNode->childLeft = BTnode;
				BTnode->parent = currentNode;

				return;
			}
			currentNode = currentNode->childLeft;
		}
		if(currentNode->key == key)
		{
			currentNode->value = value;
			
			return;
		}
	}
	currentNode = BTnode;	
}

void remove_from_BTree(struct BTree * btree, unsigned int key)
{
	if(btree == NULL || btree->root == NULL)
		return;
	
	struct BTNode * currentNode = btree->root;

	while(currentNode != NULL)
	{
		if(currentNode->key > key)
		{
			//if(){}
			currentNode = currentNode->childRight;
		}
		if(currentNode->key < key)
		{
			//if(){}
			currentNode = currentNode->childLeft;
		}
		//if()
		//{
			
		//}
	}
}
