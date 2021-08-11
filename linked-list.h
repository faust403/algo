#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ListNode
{
    char *value;

    struct ListNode *next;
};

struct List
{
    struct ListNode *head;
};

struct List *create_list()
{
    struct List *result = (struct List *)malloc(sizeof(struct List));
    result->head = NULL;

    return result;
}

void free_list(struct List *list)
{
    
}

void add_to_list(struct List *list, const char *value)
{
    if(list == NULL)
        return;

    if(value == NULL)
        return;

    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->value = (char *)malloc(strlen(value) + 1);
    strcpy(node->value, value);

    node->next = list->head;

    list->head = node;
}

void print_list(struct List *list)
{
    if(list == NULL)
        return;

    struct ListNode* node = list->head;

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
        struct ListNode *node = list->head;
        
        list->head = node->next;
        
        free(node->value);
        free(node);

        return;
    }

    struct ListNode *previous_node = list->head;
    struct ListNode *current_node = previous_node->next;

    for (size_t i = 1; i < pos; i++) {
        if(current_node == NULL)
            return;

        previous_node = current_node;
        current_node = current_node->next;
    }

    previous_node->next = current_node->next;
    
    free(current_node->value);
    free(current_node);
}

void remove_node(struct List* list, struct ListNode* node)
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

    struct ListNode *previous_node = list->head;
    struct ListNode *current_node = previous_node->next;

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

const struct ListNode *find_in_list(const struct List *list, const char *value)
{
    if(list == NULL || list->head == NULL)
        return NULL;
    
    const struct ListNode *node = list->head;

    while(node != NULL && strcmp(value, node->value) != 0)
        node = node->next;

    return node;
}

#endif