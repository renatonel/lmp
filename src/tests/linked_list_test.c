
//#define NDEBUG // Disable assert
#define TEST_OUTPUT

#include <linked_list.h>
#include <assert.h>
#include <stdio.h>

#ifdef TEST_OUTPUT
#define print_test(name, description) \
    printf("\n" name "\n" description "\n")
#else
#define print_test(name, description) __no_op__
#endif // TEST_OUTPUT

#define PASS 1
#define FAIL 0

typedef int test;
typedef int bool;

test test_linked_list_init() {
    print_test("test_linked_list_init",
           "To test that linked list initialization works");

    struct linked_list list;

    // Check that initialize method returns success
    bool init_check = linked_list_init(&list) == LL_SUCCESS;

    // Check that members have correct values
    bool size_check = list.size == 0;
    bool current_pos_check = list.current_pos == LL_STATUS_EMPTY;
    bool first_node_check = list.first_node == NULL;
    bool current_node_check = list.current_node == NULL;
    bool last_node_check = list.last_node == NULL;

    // Assertions to aid with debugging
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
        ?  PASS 
        :  FAIL;
}

test test_linked_list_add() {
    print_test("test_linked_list_add",
           "To test adding to a linked list");

    struct linked_list list;
    int content = 98;

    if (linked_list_init(&list) != LL_SUCCESS) {
        return FAIL;
    }

    bool add_first_check = 
        linked_list_add(&list, &content, 0) == LL_SUCCESS;
    
    bool size_1_check = list.size == 1;
    bool pos_1_check = list.current_pos == 0;
    bool first_node_1_check = (int)(list.first_node->content) == 98;
    bool curr_node_1_check = list.current_node->content == 98;
    bool last_node_1_check = list.last_node->content == 98;
    //list->first_node == list->current_node == list->last_node;

    assert(add_first_check);
    assert(size_1_check);
    assert(pos_1_check);
    assert(first_node_1_check);
    assert(curr_node_1_check);
    assert(last_node_1_check);

    bool first_check = add_first_check
         && size_1_check
         && pos_1_check
         && first_node_1_check
         && curr_node_1_check
         && last_node_1_check;

    return first_check
        ?  PASS
        :  FAIL;
}

int main() {
    test (*tests[])() = {
         &test_linked_list_init
        ,&test_linked_list_add
    };

    int test_count = sizeof(tests) / (8); // size of 64bit address ??
    int pass_count = 0;
    int test_nr = 0;

    printf("\n%i tests will be executed..\n", test_count);
    for (test_nr = 0; test_nr < test_count; test_nr++) {
        int test_result = tests[test_nr]();

        pass_count += test_result;

        printf("Test %i: %i\n", test_nr, test_result);
    }

    printf("\n%i Tests executed\n%i Tests passed\n%i Tests failed\n",
            test_nr, pass_count, test_nr - pass_count);

    // returns the number of tests failed,
    // else 0 for success
    return test_count - pass_count;
}

