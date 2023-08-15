/** linked_list.c
 *  Implementation for linked_list.h
 **/

#define LOG_DEBUG
#define LOG_ERROR

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
    dbg_msg("== linked_list_add ==");

    dbg_msg("Creating new node to be added");
    static struct node node;
    dbg_val(&node, "%lu");
    node.content = content;

    if (linked_list->current_node == NULL 
            && linked_list->current_pos == LL_STATUS_EMPTY 
            && linked_list->size == 0) 
    { 
        dbg_msg("List is currently empty, simply adding as only member");

        linked_list->first_node = &node;
        linked_list->last_node = &node;
        linked_list->current_node = &node;

        linked_list->size = 1;
        linked_list->current_pos = 0;

        return LL_SUCCESS;

    } else if (position == 0) {
        dbg_msg("Adding at position 0, no need for resetting or rewiring");

        linked_list->first_node = &node;
        linked_list->current_node = &node;

        linked_list->size++;
        linked_list->current_pos = position;

        return LL_SUCCESS;

    } else if (position > 0 && position <= linked_list->size) {

        struct node* prev_node; // node before the new node
                                // to be rewired to newly added node
        struct node* next_node; // node after the new node
                                // newly added node to be wired here
    
        dbg_msg("Insert in middle somewhere, so rewiring required");

        linked_list_reset(linked_list);
        for (int i = 0; i < position; i++) {
            // traverse the list untill position-1
            linked_list_next(linked_list);
        }

        prev_node = linked_list->current_node;
        // go forward 1 and save position into tmp var
        linked_list_next(linked_list);
        next_node = linked_list->current_node;

        node.next_node = next_node;
        prev_node->next_node = &node;

        linked_list->size++;
        linked_list->current_pos = position;

        return LL_SUCCESS;

    } else if (position > linked_list->size) {
        dbg_msg("Adding at end, so simply wire the last node up");

        linked_list->last_node->next_node = &node;
        linked_list->last_node = &node;

        linked_list->size++;
        linked_list->current_pos = linked_list->size - 1;

        return LL_SUCCESS;

    } else {
        error_msg("Could not determine where to add new element");
        error_msg("Possible invalid position argument provided");
        error_val(position, "%i");
        error_val(linked_list->size, "%i");

        return LL_INVALID_ARGS;
    }
}

int linked_list_remove(
        struct linked_list* linked_list, 
        int position) 
{
    return LL_NOT_YET_IMPL;
}

void* linked_list_next(
        struct linked_list* linked_list) 
{
    if (linked_list->current_node == NULL 
            && linked_list->current_pos == LL_STATUS_EMPTY 
            && linked_list->size == 0) 
    {
        // List is empty
        return NULL;
    }
    else if (linked_list->current_node != linked_list->last_node) {
        linked_list->current_node = linked_list->current_node->next_node;
        linked_list->current_pos++;
    }

    return linked_list->current_node->content;
}

void* linked_list_get(struct linked_list* linked_list) {
    return NULL;
}

int linked_list_reset(struct linked_list* linked_list) {

    if (linked_list->current_node == NULL 
            && linked_list->current_pos == LL_STATUS_EMPTY 
            && linked_list->size == 0) 
    {
        // List is empty
        return LL_SUCCESS;
    }

    linked_list->current_node = linked_list->first_node;
    linked_list->current_pos = 0;

    return LL_SUCCESS;
}
