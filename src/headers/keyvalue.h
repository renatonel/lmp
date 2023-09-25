/** \file keyvalue.h
 *
 *  A Classical key-value structure that can be used
 *  in other structures such as for example a linked_list
 **/

#ifndef __KEYVALUE_H__
#define __KEYVALUE_H__

// Return and Error codes
#define KV_SUCCESS          0x0000
#define KV_NODE_NULL        0x3001


/** A Key Value pair
 *
 **/
struct keyvalue {
    void* key;
    void* value;
};

/** Initializes the keyvalue structure
 *  
 *  @param node The keyvalue structure to be initialized
 *  @return KV_SUCCESS on success
 **/
int kv_init(struct keyvalue* node);

/** Free up keyvalue memory.
 *
 *  @param node The keyvalue structure to be freed.
 *  @return KV_SUCCESS on success
 **/
int kv_free(struct keyvalue* node);

/** Get the key for specified node.
 *
 *  @return NULL if node is NULL.
 *  @return The key.
 **/
void* kv_get_key(struct keyvalue* node);

/** Get the value for specified node.
 *
 *  @return NULL if node is NULL.
 *  @return The value.
 **/
void* kv_get_value(struct keyvalue* node);

/** Sets the key of specified node.
 *
 *  @return KV_NODE_NULL if node is NULL
 *  @return KV_SUCCESS on success
 **/
int kv_set_key(struct keyvalue* node, void* key);

/** Sets the value of specified node.
 *
 *  @return KV_NODE_NULL if node is NULL
 *  @return KV_SUCCESS on success
 **/
int kv_set_value(struct keyvalue* node, void* value);

#endif // __KEYVALUE_H__

