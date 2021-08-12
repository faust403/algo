#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

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

struct Node** create_hash_table()
{
	struct Node *hash_table[1024];
	
	int iter = 0;
	while(iter < 1024)
	{
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

void add(const char *key, const char *value, struct Node *hash_table[1024])
{
  	unsigned int index = hash(key) % 1024;
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

  	node->key = (char *)malloc(strlen(key) + 1);
  	strcpy(node->key, key);

  	node->value = (char *)malloc(strlen(value) + 1);
  	strcpy(node->value, value);

  	node->next = NULL;

  	if (hash_table[index] == NULL) {
    		hash_table[index] = node;
  	}
  	else {
    		struct Node *current = hash_table[index];
    		while (current->next != NULL)
      			current = current->next;

    		current->next = node;
  	}	
}

struct Node *find_node(const char *key, struct Node *hash_table[1024])
{
  	unsigned int index = hash(key) % 1024;
  	struct List * list = hash_table[index];

  	return find_in_list(list, key); 
}

char *find_value(const char *key)
{
  	struct Node *node = find_node(key);

  	if (node == NULL)
    		return NULL;

  	return node->value;
}

#endif
