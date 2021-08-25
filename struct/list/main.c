#include "cl-list.h"
int main()
{
	struct DL_List * cl_list = create_CL_DL_List();
	add_to_CL_DL_List(cl_list, "value1\n");
	add_to_CL_DL_List(cl_list, "value2\n");
	add_to_CL_DL_List(cl_list, "value3\n");
	clear_CL_List(cl_list);
	add_to_CL_DL_List(cl_list, "new value1\n");
	//add_to_CL_DL_List(cl_list, "new value2\n");
	print_CL_List(cl_list);
	//printf("%u", CL_List_size(cl_list));
	free_CL_List(cl_list);
	//printf("%u", CL_List_size(cl_list));
	return 0;
}
