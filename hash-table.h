#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked-list.h"

unsigned int hash(const char* str)
{
	unsigned int result = 0;
  	unsigned int power = 1;

   	while (*str != '\0')
     		result += (power *= 53) * (unsigned int)*str++;

  	return result;
}

struct List** create_hash_table()
{
	struct List *hash_table = (struct List *)malloc(1024);
	
	int iter = 0;
	while(iter < 1024)
	{
		hash_table[iter]->head = NULL;
		hash_table[iter] = NULL;
	}
	return hash_table;
}

void add_to_table(struct Node *hash_table[1024], struct Node * node)
{
	int iter = 0;
	while(hash_table[iter] != NULL)
	{
		hash_table[iter] = node;
		iter++;
	}
}

void add(const char *key, char *value, struct List *hash_table[1024])
{
  	unsigned int index = hash(key) % 1024;
	struct Node *node = create_node(value);

  	node->next = NULL;

  	if (hash_table[index] == NULL) {
    		add_to_list(hash_table[index], value);
  	}
  	else {
    		struct List *currentList = hash_table[index];
		struct Node *currentNode = currentList->head;

    		while (currentNode->next != NULL)
      			currentNode = currentNode->next;

    		currentNode->next = node;
  	}	
}

struct Node *find_node(const char *key, struct List *hash_table[1024])
{
  	unsigned int index = hash(key) % 1024;
  	struct List * list = hash_table[index];

  	return find_in_list(list, key); 
}

char *find_value(const char *key, struct List *hash_table[1024])
{
  	struct Node *node = find_node(key, hash_table);

  	if (node == NULL)
    		return NULL;

  	return node->value;
}

#endif
