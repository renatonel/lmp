#include <test.h>
#include <keyvalue.h>

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

// Array of functions returning test, taking no arguments
test (*tests[])() = {
    &test_keyvalue
};

test_main("Keyvalue tests", tests)

