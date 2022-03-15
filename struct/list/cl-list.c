#include "cl-list.h"
#include <stdio.h>
#include <stdlib.h>

struct DL_List * create_CL_DL_List()
{
	struct DL_List * dl_list = (struct DL_List *)malloc(sizeof(struct DL_List));
	if(dl_list == NULL)
		return dl_list;

	dl_list->head = NULL;

	return dl_list;
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
		dl_node->next = dl_node;
		dl_node->previous = dl_node;
		
		return;
	}
	
	dl_node->next = dl_list->head;
	dl_node->previous = dl_list->head->previous;
	dl_list->head->previous = dl_node;
	dl_node->previous->next = dl_node;
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
			if(currentNode == dl_list->head)
                        {
                                if(currentNode->previous == dl_list->head)
                                {
                                        currentNode->next = NULL;
                                        currentNode->previous = NULL;
                                        free(currentNode);
                                        currentNode = NULL;
                                        dl_list->head = NULL;

                                        return;
                                }
                        }
			if(currentNode == dl_list->head->previous)
			{
				dl_list->head->previous = currentNode->previous;
				currentNode->previous->next = dl_list->head;

				free(currentNode);
				currentNode = NULL;
			
				return;
			}

			currentNode->previous->next = currentNode->next;
			currentNode->next->previous = currentNode->previous;

			free(currentNode);
			currentNode = NULL;
			
			return;
        	}
		currentNode = currentNode->next;
	}
	while(currentNode != dl_list->head);
}

void clear_CL_List(struct DL_List * dl_list)
{
	if(dl_list == NULL || dl_list->head == NULL)
		return;

	struct DL_Node * currentNode = dl_list->head;

	if(currentNode->next == dl_list->head && currentNode->previous == dl_list->head)
	{
		free(currentNode);
		dl_list->head == NULL;
		
		return;
	}

	do
	{
		currentNode = currentNode->next;
		free(currentNode->previous);
	}
	while(currentNode->next != dl_list->head);
	free(currentNode);

	dl_list->head = NULL;
}

void free_CL_List(struct DL_List * dl_list)
{
	clear_CL_List(dl_list);
	free(dl_list);

	dl_list = NULL;
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
	if(dl_list == NULL || dl_list->head == NULL)
		return res;

	struct DL_Node * currentNode = dl_list->head;

	do
        {
                currentNode = currentNode->next;
                ++res;
        }
        while(currentNode != dl_list->head);
	
	return res;
}
