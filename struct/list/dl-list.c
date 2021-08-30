#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dl-list.h"
#include "../../util/util.h"

struct DL_Node * create_DL_Node(void * value)
{
	struct DL_Node * dl_node = (struct DL_Node *)malloc(sizeof(struct DL_Node));
	dl_node->value = value;
	dl_node->previous = NULL;
	dl_node->next = NULL;

	return dl_node;
}

struct DL_List * create_DL_List()
{
	struct DL_List * dl_list = (struct DL_List *)malloc(sizeof(struct DL_List));
	dl_list->head = NULL;

	return dl_list;
}

void add_to_DL_List(struct DL_List * dl_list, void * value)
{
        struct DL_Node * dl_node = create_DL_Node(value);

        if(dl_list->head == NULL)
        {
                dl_list->head = dl_node;
                return;
        }
	if(dl_list == NULL)
	{
		dl_list = create_DL_List();
		dl_list->head = dl_node;
		return;
	}
	
	dl_node->next = dl_list->head;
	dl_list->head->previous = dl_node;
	dl_list->head = dl_node;
}

void remove_from_DL_List(struct DL_List * dl_list, void * value)
{
	if(dl_list == NULL || dl_list->head == NULL)
		return;
	
	struct DL_Node * currentDLNode = dl_list->head;

	while(currentDLNode != NULL)
	{
		if(currentDLNode->value == value)
		{
			if(currentDLNode->previous == NULL)
        		{                                  
                		dl_list->head = currentDLNode->next;
                		
				free(currentDLNode);
				currentDLNode = NULL;
                		
				return;
        		}
			if(currentDLNode->next == NULL)
			{
				currentDLNode->previous->next = NULL;

				free(currentDLNode);
				currentDLNode = NULL;
				
				return;
			}
			currentDLNode->previous->next = currentDLNode->next;
			currentDLNode->next->previous = currentDLNode->previous;
			
			free(currentDLNode);
			currentDLNode = NULL;
			
			return;
		}
		currentDLNode = currentDLNode->next;
	}
}
void clear_DL_List(struct DL_List * dl_list)
{
	if(dl_list == NULL || dl_list->head == NULL)
                return;

        struct DL_Node * currentDLNode = dl_list->head;
        while(currentDLNode->next != NULL)
	{
		currentDLNode = currentDLNode->next;
		free(currentDLNode->previous);
	}
	dl_list->head = currentDLNode->next;
	free(currentDLNode);
}

void free_DL_List(struct DL_List * dl_list)
{
	clear_DL_List(dl_list);
	free(dl_list);
	dl_list = NULL;
}

unsigned int DL_List_size(struct DL_List * dl_list)
{
	if(dl_list == NULL || dl_list->head == NULL)
		return 0;

	unsigned int counter = 0;
	struct DL_Node * currentDLNode = dl_list->head;
	
	while(currentDLNode != NULL)
	{
		counter++;
		currentDLNode = currentDLNode->next;
	}

	return counter;
}
