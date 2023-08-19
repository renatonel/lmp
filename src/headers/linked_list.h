/** linked_list.h
 * 
 **/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// Return and Error codes
#define LL_SUCCESS          0x0000
#define LL_CORRUPTION       0x2001
#define LL_INVALID_ARGS     0x2002
#define LL_NOT_YET_IMPL     0x20FE
#define LL_ERROR_UNKNOWN    0x20FF

// Status codes
#define LL_STATUS_EMPTY         -1      ///< list is empty
#define LL_STATUS_INCONSISTENT  -99     ///< list is in inconsistent status

struct node {
    void* content;
    struct node* next_node;
};

/** A Linked List
 *  
 **/
struct linked_list {
    /** The number of nodes currently in the list.
     *  0 if list is empty.
     **/
    int size;

    /** The position of the current node.
     *  LL_STATUS_EMPTY (-1) if list is empty.
     *  0 for first element.
     *  LL_STATUS_INCONSISTENT if an inconsistent state is detected.
     **/
    int current_pos;

    /** Pointers to nodes of insterest.
     *  If list is empty, these pointers will be NULL.
     **/
    struct node* first_node;    ///< Pointer to the first node in the list.
    struct node* current_node;  ///< Pointer to the current node.
    struct node* last_node;     ///< Pointer to the last node in the list.
};


/** Initializes the linked list.
 *
 **/
int linked_list_init(struct linked_list* linked_list);

/** Free memory taken up by linked list.
 *  Frees the memory taken up by nodes within the list.
 *
 *  @linked_list list to be freed.
 *  @return number of nodes freed.
 **/
int linked_list_free(struct linked_list* linked_list);

/** Add an element to the list.
 *  On success, the current node and position is set to the
 *  newly inserted node.
 *
 *  @linked_list    list to be added to
 *  @content        The content to add to the list
 *  @position       The position of the new element. If the position
 *                  is specified as after the last element, it will
 *                  be placed as the last element instead.
 *  @returns        Result of add operation
 **/
int linked_list_add(
        struct linked_list* linked_list, 
        void* content, 
        int position);

int linked_list_remove(
        struct linked_list* linked_list, 
        int position);

/** Returns the content of the current position.
 *  
 *  @returns the content of the current position.
 **/
void* linked_list_get(struct linked_list* linked_list);

/** Moves the current position to the next node.
 *
 *  @returns the content of the new current node.
 **/
void* linked_list_next(struct linked_list* linked_list);

/** Resets the current node to the first node.
 *
 **/
int linked_list_reset(struct linked_list* linked_list);




/* optional
struct node* linked_list_current_node(struct linked_list* linked_list);

int linked_list_size(struct linked_list* linked_list);
*/

/* potential extensions
int linked_list_append(struct linked_list* linked_list, struct node* node);

int linked_list_prepend(struct linked_list* linked_list, struct node* node);

int linked_list_sorted_add(struct linked_list* linked_list, struct node* node);

int linked_list_sort(struct linked_list* linked_list);

int linked_list_find_first(struct linked_list* linked_list, struct node* node);
*/

#endif // __LINKED_LIST_H__
