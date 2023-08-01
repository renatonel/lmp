/** linked_list.h
 * 
 **/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct content;

struct node {
    struct content content;
    struct node* next_node;
}

struct linked_list {
    struct node* first_node;
};

int init_linked_list(struct linked_list* linked_list);

#endif // __LINKED_LIST_H__
