#ifndef _LIST_H_
#define _LIST_H_

struct ListNode
{
	struct ListNode* next;
	char value[0];
};

struct List
{
	struct ListNode* head;
	struct ListNode* (*create)(const void* value);
	int (*compare)(const void* a, const void* b);
};

struct List *list_create_int();
struct List *list_create_double();
struct List *list_create_string();

void list_add(struct List *list, const void *value);
int list_contains(struct List *list, const void* value);
int list_try_find(struct List* list, const void* value, struct ListNode** node_ref);
void list_for_each(struct List* list, void (*proc)(const void* value));
void list_change_node(struct List* list, struct ListNode* old_node, struct ListNode* new_node);
void list_free(struct List* list);

#endif
