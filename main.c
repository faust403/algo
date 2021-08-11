#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linked-list.h"

int main()
{
    struct List *list = create_list();
    add_to_list(list, "value1");
    add_to_list(list, "value2");
    add_to_list(list, "value3");
    add_to_list(list, "value4");
    add_to_list(list, "value5");

    /* print_list(list); */

    /* remove_from_list(list, 1); */

    struct ListNode *node = find_in_list(list, "value2");
    puts(node->value);

    /* print_list(list); */
    return 0;
}