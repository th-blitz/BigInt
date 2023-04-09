
#ifndef ByteStack_H
#define ByteStack_H

#include "stdint.h"

typedef struct ByteStack {
    struct ByteStack_node* head;
    uint64_t size;
    void (*append)(struct ByteStack* self, uint8_t value);
    void (*pop)(struct ByteStack* self);
    uint8_t (*peek)(struct ByteStack* self);
    void (*free)(struct ByteStack* self);
    void (*print)(struct ByteStack* self);
} ByteStack;

typedef struct ByteStack_node {
    uint8_t value;
    struct ByteStack_node* next;
} ByteStack_node;

ByteStack Byte_Stack();

// :: ONLY FOR TESTING ::
// void append_ByteStack(ByteStack* self, uint8_t value);
// void pop_ByteStack(ByteStack* self);
// uint8_t peek_ByteStack(ByteStack* self);
// void free_ByteStack(ByteStack* self);
// uint8_t update_byte(uint8_t byte, uint8_t bit, uint64_t index);


#endif