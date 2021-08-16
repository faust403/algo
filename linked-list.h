#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node
{
    	char *value;

	struct Node *next;
};

struct List
{
    	struct Node *head;
};

struct List *create_list()
{
    	struct List *result = (struct List *)malloc(sizeof(struct List));
    	result->head = NULL;

    	return result;
}

void add_to_list(struct List *list, char *value)
{
    	if(list == NULL)
        	return;

    	if(value == NULL)
        	return;

    	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    	node->value = (char *)malloc(strlen(value) + 1);
    	strcpy(node->value, value);

    	node->next = list->head;

    	list->head = node;
}

void print_list(struct List *list)
{
    	if(list == NULL)
        	return;

    	struct Node* node = list->head;

    	while(node != NULL) {
        	puts(node->value);
        	node = node->next;
    	}
}

void remove_at(struct List *list, size_t pos)
{
    	if(list == NULL || list->head == NULL)
        	return;

    	if(pos == 0) {
        	struct Node *node = list->head;
        
        	list->head = node->next;
        
        	free(node->value);
        	free(node);

        	return;
    	}

    	struct Node *previous_node = list->head;
    	struct Node *current_node = previous_node->next;

    	for (size_t i = 1; i < pos; i++) {
        	if(current_node == NULL)
            	return;

        	previous_node = current_node;
        	current_node = current_node->next;
    	}

    	previous_node->next = current_node->next;
    
    	free(current_node->value);
    	free(previous_node->value);
    	free(current_node);
    	free(previous_node);
}

struct Node *create_node(char *value)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->value = value;
	node->next = NULL;
	
	return node;
}

void remove_node(struct List* list, struct Node* node)
{
    	if(list == NULL || list->head == NULL)
        	return;

    	if(node == list->head)
    	{
        	list->head = node->next;

        	free(node->value);
        	free(node);

       		return;
    	}

    	struct Node *previous_node = list->head;
    	struct Node *current_node = previous_node->next;

    	while(current_node != NULL && current_node != node) {
        	previous_node = current_node;
        	current_node = current_node->next;
   	}

    	if(current_node != NULL) {
        	previous_node->next = current_node->next;

        	free(current_node->value);
        	free(current_node);
    	}
}

void clear_list(struct List *list)
{
	if(list == NULL || list->head == NULL) 
        	return;

        struct Node * previousNode = list->head->next; //Голову не зануляем
	struct Node * currentNode = previousNode->next;
        
        while(currentNode != NULL)      
        {
                free(previousNode->value);
                free(previousNode);

		previousNode = currentNode;
		currentNode = currentNode->next;
        }
	free(currentNode->value);
	free(currentNode);
	list->head = NULL;
	list = NULL;
}

void free_list(struct List *list)
{
	if(list->head == NULL || list == NULL)
	{
		free(list);
		return;
	}

	clear_list(list);
	free(list);
}

int list_size(struct List *list)
{
	if(list == NULL) return 0;

	int counter = 0;
	struct Node *node = list->head;

	while(node != NULL)
	{
		counter++;
		node = node->next;
	}
	return counter;
}

struct Node *find_in_list(const struct List *list, const char *value)
{
    	if(list == NULL || list->head == NULL)
        	return NULL;
    
    	struct Node *node = list->head;

    	while(node != NULL && strcmp(value, node->value) != 0)
        	node = node->next;

    	return node;
}

#endif
