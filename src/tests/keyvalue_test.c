//#define TEST_OUTPUT

#include <keyvalue.h>
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

test test_keyvalue() {
    
    print_test("test_keyvalue", 
            "Testing the basic functions of the keyvalue structure");

    struct keyvalue kv;

    bool init_check =  kv_init(&kv) == KV_SUCCESS
                    && kv.key       == NULL
                    && kv.value     == NULL;

    bool set_key_check =  kv_set_key(&kv, "key string") == KV_SUCCESS
                       && strcmp(kv.key, "key string")  == 0;

    bool get_key_check = strcmp(kv_get_key(&kv), "key string") == 0;

    bool set_value_check =  kv_set_value(&kv, "value string") == KV_SUCCESS
                         && strcmp(kv.value, "value string")  == 0;

    bool get_value_check = strcmp(kv_get_value(&kv), "value string") == 0;

    //bool destroy_check = kv_free(&kv) == KV_SUCCESS;

    // assertions only to aid with debugging
    assert(init_check);
    assert(set_key_check);
    assert(get_key_check);
    assert(set_value_check);
    assert(get_value_check);
    //assert(destroy_check);

    return init_check
        && set_key_check
        && get_key_check
        && set_value_check
        && get_value_check
        //&& destroy_check
        // -------------
        ?  TEST_PASS
        :  TEST_FAIL;
}

int main() {
    test (*tests[])() = {
         &test_keyvalue
    };

    int test_count = sizeof(tests) / (8); // size of 64bit address ??
    int pass_count = 0;
    int test_nr = 0;

    printf("\nKeyvalue tests\n");

#ifdef TEST_OUTPUT
    printf("\n%i tests will be executed..\n", test_count);
#endif // TEST_OUTPUT
    for (test_nr = 0; test_nr < test_count; test_nr++) {
        int test_result = tests[test_nr]();

        pass_count += test_result;

#ifdef TEST_OUTPUT
        printf("Test %i: %i\n", test_nr, test_result);
#endif // TEST_OUTPUT
    }

    printf("\n%i Tests executed\n%i Tests passed\n%i Tests failed\n",
            test_nr, pass_count, test_nr - pass_count);

    // returns the number of tests failed,
    // else 0 for success
    return test_count - pass_count;
}

