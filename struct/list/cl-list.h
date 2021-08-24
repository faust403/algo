#ifndef __CL_LIST_H__
#define __CL_LIST_H__

#include "liner-list.h"
#include "dl-list.h"

struct DL_List * create_CL_DL_List();
struct List * create_CL_list();
void add_to_CL_DL_List(struct DL_List * dl_list, char * value);
void remove_from_CL_DL_List(struct DL_List * dl_list, char * value);
void print_list(struct DL_List * dl_list);

#endif
