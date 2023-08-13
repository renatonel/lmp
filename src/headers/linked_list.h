/** linked_list.h
 * 
 **/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// Error codes
#define LL_SUCCESS          0x0000
#define LL_UNKNOWN_ERROR    0x20FF

struct node {
    void* content;
    struct node* next_node;
};

struct linked_list {
    int size;
    int current_pos;

    struct node* first_node;
    struct node* current_node;
    struct node* last_node;
};

int linked_list_init(struct linked_list* linked_list);

int linked_list_add(struct linked_list* linked_list, struct node* node, int position);

int linked_list_remove(struct linked_list* linked_list, struct node* node);

struct node* linked_list_next_node(struct linked_list* linked_list);

/* optional
struct node* linked_list_current_node(struct linked_list* linked_list);

int linked_list_size(struct linked_list* linked_list);

int linked_list_current_pos(struct linked_list* linked_list);
*/

/* potential extensions
int linked_list_append(struct linked_list* linked_list, struct node* node);

int linked_list_prepend(struct linked_list* linked_list, struct node* node);

int linked_list_sorted_add(struct linked_list* linked_list, struct node* node);

int linked_list_sort(struct linked_list* linked_list);

int linked_list_find_first(struct linked_list* linked_list, struct node* node);
*/

#endif // __LINKED_LIST_H__
