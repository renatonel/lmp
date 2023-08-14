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

int linked_list_add(
        struct linked_list* linked_list, 
        void* content, 
        int position) 
{    
    linked_list_reset(linked_list);
    for (int i = 0; i < position; i++) {
        // traverse the list until position-1
        linked_list_next_node(linked_list);
    }
    
    // save position-1 into tmp var
    struct node* prev_node, next_node;
    if (linked_list->current_pos == position - 1) {
        prev_node = linked_list->current_node;
        
        // go forward 1 and save position into tmp var
        linked_list_next_node(linked_list);
        if (linked_list->current_pos == position) {
            next_node = linked_list->current_node;
        } else {
            linked_list->current_pos = LL_STATUS_INCONSISTENT;

            return LL_CORRUPTION;
        }
    } else {
        linked_list->current_pos = LL_STATUS_INCONSISTENT;

        return LL_CORRUPTION;
    }

    // rewire pointers and insert new node
    struct node node;
    node.content = *content;
    node.next_node = next_node;

    prev_node->next_node = &node;

    return LL_SUCCESS;
}

int linked_list_remove(
        struct linked_list* linked_list, 
        int position) 
{
    return LL_NOT_YET_IMPL;
}

void* linked_list_next_node(
        struct linked_list* linked_list) 
{
    if (linked_list->current_node != linked_list->last_node) {
        linked_list->current_node = linked_list->current_node->next_node;
        linked_list->current_pos++;
    }

    return linked_list->current_node->content;
}

int linked_list_reset(struct linked_list* linked_list) {
    linked_list->current_node = linked_list->first_node;
    linked_list->current_pos = 0;

    return LL_SUCCESS;
}
