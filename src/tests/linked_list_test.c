
//#define NDEBUG // Disable assert

#include <linked_list.h>
#include <assert.h>
#include <stdio.h>

#define PASS 1
#define FAIL 0

typedef int test;
typedef int bool;

test test_linked_list_init() {
    printf("test_linked_list_init\n"
           "To test that linked list initialization works\n");

    struct linked_list list;

    bool init_check = linked_list_init(&list) == LL_SUCCESS;
    bool size_check = list.size == 0;
    bool current_pos_check = list.current_pos == -1;
    bool first_node_check = list.first_node == NULL;
    bool current_node_check = list.current_node == NULL;
    bool last_node_check = list.last_node == NULL;

    assert(init_check);
    assert(size_check);
    assert(current_pos_check);
    assert(first_node_check);
    assert(current_node_check);
    assert(last_node_check);

    return init_check 
        && size_check
        && current_pos_check
        && first_node_check
        && current_node_check
        && last_node_check
        ? PASS 
        : FAIL;
}

test test_linked_list_add() {
    struct node node;
    struct linked_list list;

    //assert(append_linked_list(&list, &node) == LL_SUCCESS);
    //assert();

    return PASS;
}

int main() {
    test (*tests[])() = {
        &test_linked_list_init,
        &test_linked_list_add
    };

    int test_count = sizeof(tests) / (8); // size of 64bit address ??
    int pass_count = 0;
    int test_nr = 0;

    printf("%i tests will be executed..\n", test_count);
    for (test_nr = 0; test_nr < test_count; test_nr++) {
        int test_result = tests[test_nr]();

        pass_count += test_result;

        printf("Test %i: %i\n", test_nr, test_result);
    }

    printf("%i Tests executed\n%i Tests passed\n%i Tests failed\n",
            test_nr, pass_count, test_nr - pass_count);

    // returns the number of tests failed,
    // else 0 for success
    return test_count - pass_count;
}

