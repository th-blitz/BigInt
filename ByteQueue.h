#ifndef ByteQueue_H
#define ByteQueue_H

#include <stdint.h>

typedef struct ByteQueue {
    struct ByteQueue_node* right;
    struct ByteQueue_node* left;
    uint64_t size;
    void (*append_right)(struct ByteQueue* self, uint8_t value);
    void (*append_left)(struct ByteQueue* self, uint8_t value);
    uint8_t (*pop_right)(struct ByteQueue* self);
    uint8_t (*pop_left)(struct ByteQueue* self);
    uint8_t (*peek_right)(struct ByteQueue* self);
    uint8_t (*peek_left)(struct ByteQueue* self);
    void (*free)(struct ByteQueue* self);
    void (*print)(struct ByteQueue* self);
    void (*print_hex)(struct ByteQueue* self);
} ByteQueue;

typedef struct ByteQueue_node {
    uint8_t value;
    struct ByteQueue_node* right;
    struct ByteQueue_node* left;
} ByteQueue_node;

ByteQueue Byte_Queue();


#endif