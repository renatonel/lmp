
#ifndef __TEST_H__
#define __TEST_H__

#include <string.h>
#include <assert.h>
#include <stdio.h>

#ifdef TEST_OUTPUT
#define print_test(name, description) \
    printf("\n" name "\n" description "\n")
#else
#define print_test(name, description) 
#endif // TEST_OUTPUT

#define TEST_PASS 1
#define TEST_FAIL 0

typedef int test;
typedef int bool;

/** Entry point for tests.
 *
 *  @param test_name The name of the test application.
 *  @param test_list A list with all tests to be executed.
 *
 *  Example: test_main("Keyvalue Tests", {&test_keyvalue, &test_init, &test_destroy})
 **/
#define test_main(test_name, tests)                                         \
    int main() {                                                            \
                                                                            \
        int test_count = sizeof(tests) / (8);                               \
        int pass_count = 0;                                                 \
        int test_nr = 0;                                                    \
                                                                            \
        printf("\n" test_name "\n=========================\n");             \
                                                                            \
        for (test_nr = 0; test_nr < test_count; test_nr++) {                \
            int test_result = tests[test_nr]();                             \
                                                                            \
            pass_count += test_result;                                      \
                                                                            \
        }                                                                   \
                                                                            \
        printf("\n%i Tests executed\n%i Tests passed\n%i Tests failed\n\n", \
                test_nr, pass_count, test_nr - pass_count);                 \
                                                                            \
        return test_count - pass_count;                                     \
    }                                                                       \

#endif // __TEST_H__
