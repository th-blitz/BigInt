#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#include "ByteStack.h"
#include "BigInt.h"

int is_bigendian() {
    int i = 1;
    return *(char*)&i; // if returns 1 (bit endian) else 0 (little endian).
}


static uint32_t word_mask[4] = {
    0x80000000, 0x800000, 0x8000, 0x80
};


uint128_t BigInt128(ByteStack* bytes) {
    uint128_t integer = {.array = {0}, .type = uint128};
    ByteStack_node* node_pointer = bytes -> head;
    uint32_t word;
    if (is_bigendian() == 0) {
        for (uint8_t i = 0; i < uint128; i++) {
            word = 0;
            for (uint8_t j = 0; j < 4; j++) {
                word <<= 8;
                word |= (uint32_t)(node_pointer -> value);
                node_pointer = node_pointer -> next;
            }
            integer.array[i] = word;
        }
    } else {
        for (uint8_t i = uint128; i > 0; i--) {
            word = 0;
            for (uint8_t j = 0; j < 4; j++) {
                word <<= 8;
                word |= (uint32_t)(node_pointer -> value);
                node_pointer = node_pointer -> next;
            }
            integer.array[i - 1] = word;
        }
    }
    
    return integer;
}

uint32_t BigInt128_add(uint128_t * a, uint128_t * b, uint128_t * c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint128; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return carry;
}

void print_bigint(uint128_t * a) {
    for (uint8_t i = a -> type; i > 0; i--) {
        printf("%08x", a -> array[i - 1]);
    }
    printf("\n");
}