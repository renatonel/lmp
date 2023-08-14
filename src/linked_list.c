/** linked_list.c
 *  Implementation for linked_list.h
 **/

#include <debug_logging.h>
#include <linked_list.h>
#include <stdio.h>

int linked_list_init(struct linked_list* linked_list) {
    linked_list->size = 0;
    linked_list->current_pos = LL_STATUS_EMPTY;
    linked_list->first_node = NULL;
    linked_list->current_node = NULL;
    linked_list->last_node = NULL;
    
    return LL_SUCCESS;
}

int linked_list_add(struct linked_list* linked_list, struct node* node, int position) {
    return LL_NOT_YET_IMPL;
}

int linked_list_remove(struct linked_list* linked_list, struct node* node) {
    return LL_NOT_YET_IMPL;
}

struct node* linked_list_next_node(struct linked_list* linked_list) {
    return NULL;
}
