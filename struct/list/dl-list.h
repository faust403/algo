#ifndef __DL_LIST_H__
#define __DL_LIST_H__

struct DL_Node
{
	char * value;
	struct DL_Node * next;
	struct DL_Node * previous;
};
struct DL_List
{
	struct DL_Node * head;
};

struct DL_Node * create_DL_Node(char * value);
struct DL_List * create_DL_List();
void add_to_DL_List(struct DL_List * dl_list, char * value);
void remove_from_DL_List(struct DL_List * dl_list, char * value);
void print_DL_List(struct DL_List * dl_list);
void free_DL_List(struct DL_List * dl_list);
unsigned int DL_List_size(struct DL_List * dl_list);
void clear_DL_List(struct DL_List * dl_list);

#endif
