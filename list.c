#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <string.h>

#include "list.h"

struct StringList* string_list_create() 
{
	struct StringList* list = (struct StringList*)malloc(sizeof(struct StringList));
	if (list == NULL)
		return NULL;

	list->head = NULL;

	return list;
}

void string_list_add(struct StringList* list, const char* value) 
{
	if (list == NULL)
		return;

	size_t value_size = strlen(value) + 1;
	struct StringListNode* node = (struct StringListNode*)malloc(sizeof(struct StringListNode) + value_size);
	if (node == NULL)
		return;

	strcpy(node->value, value);

	node->next = list->head;
	list->head = node;
}

int string_list_try_find(struct StringList* list, const char* value, struct StringListNode** node_ref)
{
	if (list == NULL)
		return 0;

	struct StringListNode* node = list->head;
	while (node != NULL) {
		if (strcmp(node->value, value) == 0)
		{
			if (node_ref != NULL)
				*node_ref = node;

			return 1;
		}

		node = node->next;
	}

	return 0;
}

struct IntList* int_list_create()
{
	struct IntList* intlist = (struct IntList*)malloc(sizeof(struct IntList));
	if (intlist == NULL)
		return NULL;

	intlist->head = NULL;

	return intlist;
}

void int_list_add(struct IntList* list, int value)
{
	if (list == NULL)
		return;
	
	struct IntListNode* node = (struct IntListNode*)malloc(sizeof(struct IntListNode));
	if (node == NULL)
		return;
	
	node->value = value;
	node->next = list->head;
	list->head = node;
}

int int_list_try_find(struct IntList* list, int value, struct IntListNode** node_ref)
{
	if (list == NULL)
		return 0;

	struct IntListNode* node = list->head;
	while (node != NULL) {
		if (node->value == value)
		{
			if (node_ref != NULL)
				*node_ref = node;

			return 1;
		}

		node = node->next;
	}

	return 0;
}


static struct ListNode* create_node_int(const void* value)
{
	struct ListNode* result = malloc(sizeof(struct ListNode) + sizeof(int));
	if (result == 0)
		return 0;

	result->next = 0;
	*(int*)result->value = *(const int*)value;

	return result;
}

static int compare_int(const void* a, const void* b)
{
	return *(const int*)a - *(const int*)b;
}

static struct ListNode* create_node_double(const void* value)
{
	struct ListNode* result = malloc(sizeof(struct ListNode) + sizeof(double));
	if (result == 0)
		return 0;

	result->next = 0;
	*(double*)result->value = *(const double*)value;

	return result;
}

static int compare_double(const void* a, const void* b)
{
	if ((const double*)a > (const double*)b)
		return 1;

	if ((const double*)a < (const double*)b)
		return -1;

	return 0;
}

static struct ListNode* create_node_string(const void* value)
{
	size_t string_size = strlen(value) + 1;
	struct ListNode* result = malloc(sizeof(struct ListNode) + string_size);
	if (result == 0)
		return 0;

	result->next = 0;
	strcpy_s(result->value, string_size, value);

	return result;
}

struct List* list_create_int()
{
	struct List* result = malloc(sizeof(struct List));
	if (result == 0)
		return 0;

	result->head = 0;
	result->create = create_node_int;
	result->compare = compare_int;

	return result;
}

struct List* list_create_double()
{
	struct List* result = malloc(sizeof(struct List));
	if (result == 0)
		return 0;

	result->head = 0;
	result->create = create_node_double;
	result->compare = compare_double;

	return result;
}

struct List* list_create_string()
{
	struct List* result = malloc(sizeof(struct List));
	if (result == 0)
		return 0;

	result->head = 0;
	result->create = create_node_string;
	result->compare = strcmp;

	return result;
}

void list_add(struct List* list, void* value)
{
	if (list == 0 || value == 0)
		return;

	struct ListNode* node = list->create(value);

	node->next = list->head;
	list->head = node;
}

int list_contains(struct List* list, const void* value)
{
	return list_try_find(list, value, 0);
}

int list_try_find(struct List* list, const void* value, struct ListNode** node_ref)
{
	if (list == 0 || value == 0)
		return 0;

	struct ListNode* node = list->head;
	while (node != 0) {
		if (list->compare(node->value, value) == 0) {
			if (node_ref != 0)
				*node_ref = node;

			return 1;
		}

		node = node->next;
	}

	return 0;
}

void list_for_each(struct List* list, void (*proc)(const void* value))
{
	if (list == 0)
		return;

	struct ListNode* node = list->head;
	while (node != 0) {
		proc(node->value);

		node = node->next;
	}
}

void list_change_node(struct List* list, struct ListNode* old_node, struct ListNode* new_node)
{
	if (list == 0 || old_node == 0 || new_node == 0)
		return;

	if (list->head == old_node) {
		list->head = new_node;

		return;
	}

	struct ListNode* node = list->head;
	while (node != 0) {
		if (node->next == old_node) {
			new_node->next = old_node->next;
			old_node->next = 0;
			node->next = new_node;

			return;
		}

		node = node->next;
	}
}

static void free_node(struct ListNode* node)
{
	if (node == 0)
		return;

	free_node(node->next);
	free(node);
}

void list_free(struct List* list)
{
	if (list == 0)
		return;

	free_node(list->head);

	free(list);
}
