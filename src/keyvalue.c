#include <keyvalue.h>
#include <stdio.h>
#include <stdlib.h>

int kv_init(struct keyvalue* node) {
    node->key = NULL;
    node->value = NULL;

    return KV_SUCCESS;
}

int kv_free(struct keyvalue* node) {
    //free(node->key);
    //free(node->value);
    //free(node);

    return KV_SUCCESS;
}

void* kv_get_key(struct keyvalue* node) {
    if (node == NULL) {
        return NULL;
    }

    return node->key;
}

void* kv_get_value(struct keyvalue* node) {
    if (node == NULL) {
        return NULL;
    }

    return node->value;
}

int kv_set_key(struct keyvalue* node, void* key) {
    if (node == NULL) {
        return KV_NODE_NULL;
    }

    node->key = key;

    return KV_SUCCESS;
}

int kv_set_value(struct keyvalue* node, void* value) {
    if (node == NULL) {
        return KV_NODE_NULL;
    }

    node->value = value;

    return KV_SUCCESS;
}
