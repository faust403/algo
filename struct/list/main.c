#include "cl-list.h"
int main()
{
	struct DL_List * cl_list = create_CL_DL_List();

	add_to_CL_DL_List(cl_list, "value1\n");
	add_to_CL_DL_List(cl_list, "value2\n");
	add_to_CL_DL_List(cl_list, "value3\n");
	add_to_CL_DL_List(cl_list, "value4\n");

	//remove_from_CL_DL_List(cl_list, "value2\n");
        //remove_from_CL_DL_List(cl_list, "value3\n");
        remove_from_CL_DL_List(cl_list, "value1\n");
        //remove_from_CL_DL_List(cl_list, "value4\n");

	//print_list(cl_list);

	//free_DL_List(cl_list);

	return 0;
}
