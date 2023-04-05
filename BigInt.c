#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"



#include "ByteStack.h"
#include "BigInt.h"


static uint32_t word_mask[4] = {
    0x80000000, 0x800000, 0x8000, 0x80
};


uint128_t BigInt128(ByteStack* bytes) {
    uint128_t integer = {.array = {0}, .type = uint128};
    ByteStack_node* node_pointer = bytes -> head;
    uint32_t word;
    for (uint8_t i = 0; i < uint128; i++) {
        word = 0;
        for (uint8_t j = 0; j < 4; j++) {
            word <<= 8;
            word |= (uint32_t)(node_pointer -> value);
            node_pointer = node_pointer -> next;
        }
        integer.array[i] = word;
    }
    return integer;
}

uint16_t BigInt128_add(uint128_t * a, uint128_t * b, uint128_t * c) {
    uint64_t carry = 0;
    for (uint8_t i = uint128; i > 0; i--) {
        carry = a -> array[i - 1] + b -> array[i - 1] + carry;
        c -> array[i - 1] = (uint32_t)carry;
        carry >>= 32;
    }
    return carry;
}

void print_bigint(uint128_t * a) {
    for (uint8_t i = 0; i < a -> type; i++) {
        printf("%x", a -> array[i]);
    }
    printf("\n");
}