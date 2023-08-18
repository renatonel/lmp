
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

#define TEST_PASS 1
#define TEST_FAIL 0

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
        ?  TEST_PASS 
        :  TEST_FAIL;
}

test test_linked_list_add() {

    print_test("test_linked_list_add",
           "To test adding to a linked list");

    struct linked_list list;
    int content = 98;

    // initialise the list
    if (linked_list_init(&list) != LL_SUCCESS) {
        return TEST_FAIL;
    }

    // Test to add the first element
    bool add_first_check = 
        linked_list_add(&list, &content, 0) == LL_SUCCESS;
    
    bool size_1_check = list.size == 1;
    bool pos_1_check = list.current_pos == 0;
    bool first_node_1_check = (*(int*)list.first_node->content) == 98;
    bool curr_node_1_check = (*(int*)list.current_node->content) == 98;
    bool last_node_1_check = (*(int*)list.last_node->content) == 98;
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
        ?  TEST_PASS
        :  TEST_FAIL;
}

test test_linked_list_add_front() {

    print_test("test_linked_list_add_front",
           "To test adding elements to front of linked list");

    struct linked_list list;

    int node3 = 10;
    int node2 =  5;
    int node1 =  1;

    // initialise the list and add elements
    if (    linked_list_init(&list)             != LL_SUCCESS
        ||  linked_list_add(&list, &node3, 0)   != LL_SUCCESS
        ||  linked_list_add(&list, &node2, 0)   != LL_SUCCESS
        ||  linked_list_add(&list, &node1, 0)   != LL_SUCCESS
    ) {
        return TEST_FAIL;
    }

    bool size_check         = list.size                           == 3;

    // current position = 0
    bool pos_0_check        = list.current_pos                    == 0;
    bool first_node_0_check = (*(int*)list.first_node->content)   == 1;
    bool curr_node_0_check  = (*(int*)list.current_node->content) == 1;
    bool last_node_0_check  = (*(int*)list.last_node->content)    == 10;

    // current possition = 1
    linked_list_next(&list);
    bool pos_1_check        = list.current_pos                    == 1;
    bool first_node_1_check = (*(int*)list.first_node->content)   == 1;
    bool curr_node_1_check  = (*(int*)list.current_node->content) == 5;
    bool last_node_1_check  = (*(int*)list.last_node->content)    == 10;

    // current possition = 2
    linked_list_next(&list);
    bool pos_2_check        = list.current_pos                    == 2;
    bool first_node_2_check = (*(int*)list.first_node->content)   == 1;
    bool curr_node_2_check  = (*(int*)list.current_node->content) == 10;
    bool last_node_2_check  = (*(int*)list.last_node->content)    == 10;

    // current possition remains 2 when trying to move to next position
    linked_list_next(&list);
    bool pos_3_check        = list.current_pos                    == 2;
    bool first_node_3_check = (*(int*)list.first_node->content)   == 1;
    bool curr_node_3_check  = (*(int*)list.current_node->content) == 10;
    bool last_node_3_check  = (*(int*)list.last_node->content)    == 10;

    // current possition = 0 after position reset
    linked_list_reset(&list);
    bool pos_4_check        = list.current_pos                    == 0;
    bool first_node_4_check = (*(int*)list.first_node->content)   == 1;
    bool curr_node_4_check  = (*(int*)list.current_node->content) == 1;
    bool last_node_4_check  = (*(int*)list.last_node->content)    == 10;

    
    assert(size_check);
    assert(pos_0_check);
    assert(first_node_0_check);
    assert(curr_node_0_check);
    assert(last_node_0_check);
    assert(pos_1_check);
    assert(first_node_1_check);
    assert(curr_node_1_check);
    assert(last_node_1_check);
    assert(pos_2_check);
    assert(first_node_2_check);
    assert(curr_node_2_check);
    assert(last_node_2_check);
    assert(pos_3_check);
    assert(first_node_3_check);
    assert(curr_node_3_check);
    assert(last_node_3_check);
    assert(pos_4_check);
    assert(first_node_4_check);
    assert(curr_node_4_check);
    assert(last_node_4_check);

    bool first_check_0 = pos_0_check
         && first_node_0_check
         && curr_node_0_check
         && last_node_0_check;

    bool first_check_1 = pos_1_check
         && first_node_1_check
         && curr_node_1_check
         && last_node_1_check;

    bool first_check_2 = pos_2_check
         && first_node_2_check
         && curr_node_2_check
         && last_node_2_check;

    bool first_check_3 = pos_3_check
         && first_node_3_check
         && curr_node_3_check
         && last_node_3_check;

    bool first_check_4 = pos_4_check
         && first_node_4_check
         && curr_node_4_check
         && last_node_4_check;

    return size_check
        && first_check_0
        && first_check_1
        && first_check_2
        && first_check_3
        && first_check_4
        ?  TEST_PASS
        :  TEST_FAIL;
}

test test_linked_list_add_back() {

    print_test("test_linked_list_add_back",
           "To test adding elements to end of linked list");

    struct linked_list list;

    int node1 =  1;
    int node2 =  5;
    int node3 = 10;

    // initialise the list and add elements
    if (linked_list_init(&list) != LL_SUCCESS) {
        return TEST_FAIL;
    }


    // adding first node
    bool add_node1_check        = linked_list_add(
                                  &list, &node1, list.size)  == LL_SUCCESS;
    bool node1_size_check       = list.size                           == 1;
    bool node1_pos_check        = list.current_pos                    == 0;
    bool node1_first_node_check = (*(int*)list.first_node->content)   == 1;
    bool node1_curr_node_check  = (*(int*)list.current_node->content) == 1;
    bool node1_last_node_check  = (*(int*)list.last_node->content)    == 1;

    bool node1_check = add_node1_check
        && node1_size_check
        && node1_pos_check
        && node1_first_node_check
        && node1_curr_node_check
        && node1_last_node_check;

    assert(node1_check);


    // adding second node to the back
    bool add_node2_check        = linked_list_add(
                                  &list, &node2, list.size)  == LL_SUCCESS;
    bool node2_size_check       = list.size                           == 2;
    bool node2_pos_check        = list.current_pos                    == 1;
    bool node2_first_node_check = (*(int*)list.first_node->content)   == 1;
    bool node2_curr_node_check  = (*(int*)list.current_node->content) == 5;
    bool node2_last_node_check  = (*(int*)list.last_node->content)    == 5;

    assert(add_node2_check);
    assert(node2_size_check);
    assert(node2_pos_check);
    assert(node2_first_node_check);
    assert(node2_curr_node_check);
    assert(node2_last_node_check);

    bool node2_check = add_node1_check
        && node2_size_check
        && node2_pos_check
        && node2_first_node_check
        && node2_curr_node_check
        && node2_last_node_check;

    assert(node2_check);

    // adding third node to the back
    bool add_node3_check        = linked_list_add(
                                  &list, &node3, list.size)  == LL_SUCCESS;
    bool node3_size_check       = list.size                           == 3;
    bool node3_pos_check        = list.current_pos                    == 2;
    bool node3_first_node_check = (*(int*)list.first_node->content)   == 1;
    bool node3_curr_node_check  = (*(int*)list.current_node->content) == 10;
    bool node3_last_node_check  = (*(int*)list.last_node->content)    == 10;

    assert(add_node3_check);
    assert(node3_size_check);
    assert(node3_pos_check);
    assert(node3_first_node_check);
    assert(node3_curr_node_check);
    assert(node3_last_node_check);

    bool node3_check = add_node1_check
        && node3_size_check
        && node3_pos_check
        && node3_first_node_check
        && node3_curr_node_check
        && node3_last_node_check;

    assert(node3_check);


    // checking that you cannot advance past the last element
    linked_list_next(&list);
    
    bool node4_size_check       = list.size                           == 3;
    bool node4_pos_check        = list.current_pos                    == 2;
    bool node4_first_node_check = (*(int*)list.first_node->content)   == 1;
    bool node4_curr_node_check  = (*(int*)list.current_node->content) == 10;
    bool node4_last_node_check  = (*(int*)list.last_node->content)    == 10;

    assert(node4_size_check);
    assert(node4_pos_check);
    assert(node4_first_node_check);
    assert(node4_curr_node_check);
    assert(node4_last_node_check);

    bool node4_check = node4_size_check
        && node4_pos_check
        && node4_first_node_check
        && node4_curr_node_check
        && node4_last_node_check;

    assert(node4_check);


    return node1_check
        && node2_check
        && node3_check
        && node4_check
        ?  TEST_PASS
        :  TEST_FAIL;
}

int main() {
    test (*tests[])() = {
         &test_linked_list_init
        ,&test_linked_list_add
        ,&test_linked_list_add_front
        ,&test_linked_list_add_back
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

