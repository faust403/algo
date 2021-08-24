#include "cl-list.h"
#include <stdlib.h>

struct DL_List * create_CL_DL_List()
{
	struct DL_List * dl_list = (struct DL_List *)malloc(sizeof(struct DL_List));
	dl_list->head = NULL;

	return dl_list;
}

struct List * create_CL_List()
{
	struct List * list = (struct List *)malloc(sizeof(struct List));
	list->head = NULL;

	return list;
}

void add_to_CL_DL_List(struct DL_List * dl_list, char * value)
{
	struct DL_Node * dl_node = create_DL_Node(value);

	if(dl_list == NULL)
	{
		dl_list = create_CL_DL_List();
		dl_list->head = dl_node;
		dl_node->next = dl_node;
		dl_node->previous = dl_node;

		return;
	}
	if(dl_list->head == NULL)
	{
		dl_list->head = dl_node;
		dl_node->next = dl_list->head;
		dl_node->previous = dl_list->head;
		
		return;
	}
	
	dl_node->previous = dl_list->head->previous;
	dl_list->head->previous->next = dl_node;
	dl_node->next = dl_list->head;
	dl_list->head->previous = dl_node;
	dl_list->head = dl_node;
}

void remove_from_CL_DL_List(struct DL_List * dl_list, char * value)
{
	if(dl_list == NULL || dl_list->head == NULL)
		return;

	struct DL_Node * currentNode = dl_list->head;
	
	do
	{
		if(currentNode->value == value)
		{
			if(currentNode == dl_list->head->previous)
			{
				dl_list->head->previous = currentNode->previous;
				currentNode->previous->next = dl_list->head;
			
				free(currentNode);
				currentNode = NULL;
			
				return;
			}
			if(currentNode == dl_list->head)
			{
				if(currentNode->previous == dl_list->head)
				{
					free(currentNode);
					currentNode = NULL;
					dl_list->head = NULL;
					dl_list = NULL;

					return;
				}
			}
	
			currentNode->previous->next = currentNode->next;
			currentNode->next->previous = currentNode->previous;
			dl_list->head = currentNode->next;

			free(currentNode);
			currentNode = NULL;
			
			return;
        	}
		currentNode = currentNode->next;
	}
	while(currentNode != dl_list->head);
}

void print_CL_List(struct DL_List * dl_list)
{
	if(dl_list == NULL || dl_list->head == NULL)
		return;

	struct DL_Node * currentNode = dl_list->head;

	do
	{
		printf("%s", currentNode->value);

		currentNode = currentNode->next;
	}
	while(currentNode != dl_list->head);
}

unsigned int CL_List_size(struct DL_List * dl_list)
{
	unsigned int res = 0;

	struct DL_Node * currentNode = dl_list->head;
	do
	{
		currentNode = currentNode->next;
		res++;
	}
	while(currentNode != dl_list->head);

	return res;
} 
