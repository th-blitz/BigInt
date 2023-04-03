#include "stdint.h"
#include "stdlib.h"

#include "ByteStack.h"

static uint8_t byte_mask[8] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 
};

typedef struct ByteStack_node {
    uint8_t value;
    struct ByteStack_node* next;
} ByteStack_node;

void append_ByteStack(ByteStack* self, uint8_t value) {
    ByteStack_node* new_node = (ByteStack_node*)malloc(sizeof(ByteStack_node));
    new_node -> value = value;
    new_node -> next = self -> head;
    self -> head = new_node;
    self -> size += 1;
}

void pop_ByteStack(ByteStack* self) {
    if (self -> size > 0) {
        ByteStack_node* del = self -> head;
        self -> head = self -> head -> next;
        free(del);
        self -> size -= 1;
    }
}

uint8_t peek_ByteStack(ByteStack* self) {
    return self -> head -> value;
}

void free_ByteStack(ByteStack* self) {
    while (self -> size > 0) {
        self -> pop(self);
    }
}

uint8_t update_byte(uint8_t byte, uint8_t bit, uint64_t index) {
    switch (bit) {
        case 0:
            byte &= (~ byte_mask[index]);
            break;
        case 1:
            byte |= (  byte_mask[index]);
            break;
    }
    return byte;
}

ByteStack Byte_Stack() {
    ByteStack stack = {
        .head = NULL,
        .size = 0,
        .append = append_ByteStack,
        .pop = pop_ByteStack,
        .peek = peek_ByteStack,
        .free = free_ByteStack
    };
    return stack;
}
